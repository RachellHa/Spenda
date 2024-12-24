#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "atransaction.h"
#include "transaction.h"
#include "vbudget.h"
#include "cbudget.h"

// Mock class for QMessageBox to simulate warnings
class MockMessageBox {
public:
    MOCK_METHOD(void, warning, (QWidget *, const QString &, const QString &));
};

MockMessageBox* mockMessageBox = nullptr;

// Replace QMessageBox::warning with a mock function for testing
namespace QMessageBox {
void warning(QWidget* parent, const QString& title, const QString& text) {
    if (mockMessageBox) {
        mockMessageBox->warning(parent, title, text);
    }
}
}

// Fixture class for tests
class TransactionTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Reset transaction list before each test
        transaction::transactionList.clear();
    }
};

// Test that adding a transaction properly updates the static list
TEST_F(TransactionTest, AddTransactionUpdatesList) {
    // Simulate a transaction window
    atransaction addTransactionWindow;

    // Set input values for the test
    addTransactionWindow.ui->checkBox_2->setChecked(true); // Deposit
    addTransactionWindow.ui->lineEdit->setText("Test Merchant");
    addTransactionWindow.ui->lineEdit_2->setText("50");    // Valid cost
    addTransactionWindow.ui->lineEdit_3->setText("Test Category");

    // Simulate clicking the Save button
    addTransactionWindow.onSaveClicked();

    // Verify that the transaction was added to the list
    ASSERT_EQ(transaction::transactionList.size(), 1);
    EXPECT_EQ(transaction::transactionList[0].contains("Deposit"), true);
}

// Test that Deposit and Purchase cannot be selected simultaneously
TEST_F(TransactionTest, MutuallyExclusiveCheckboxes) {
    // Simulate a transaction window
    atransaction addTransactionWindow;

    // Check Deposit and then check Purchases
    addTransactionWindow.ui->checkBox_2->setChecked(true); // Deposit
    addTransactionWindow.onDepositChecked(Qt::Checked);

    addTransactionWindow.ui->checkBox_3->setChecked(true); // Purchases
    addTransactionWindow.onPurchasesChecked(Qt::Checked);

    // Verify that only Purchases is checked
    EXPECT_FALSE(addTransactionWindow.ui->checkBox_2->isChecked());
    EXPECT_TRUE(addTransactionWindow.ui->checkBox_3->isChecked());
}

// Test that the cost must be numeric and positive
TEST_F(TransactionTest, CostMustBeNumericAndPositive) {
    // Mock QMessageBox to capture warnings
    MockMessageBox mockBox;
    mockMessageBox = &mockBox;

    EXPECT_CALL(mockBox, warning(::testing::_, ::testing::_, ::testing::ContainsRegex("Please enter a valid amount")))
        .Times(1);

    // Simulate a transaction window
    atransaction addTransactionWindow;

    // Set invalid cost value
    addTransactionWindow.ui->checkBox_2->setChecked(true); // Deposit
    addTransactionWindow.ui->lineEdit->setText("Test Merchant");
    addTransactionWindow.ui->lineEdit_2->setText("InvalidCost"); // Invalid cost
    addTransactionWindow.ui->lineEdit_3->setText("Test Category");

    // Simulate clicking the Save button
    addTransactionWindow.onSaveClicked();

    // Verify no transactions were added
    EXPECT_EQ(transaction::transactionList.size(), 0);

    // Clean up mock
    mockMessageBox = nullptr;
}

TEST(cBudgetTest, CreateBudgetInvalidInput) {
    cBudget budgetWindow;

    // Simulate invalid inputs
    budgetWindow.ui->lineEdit->setText("Food");
    budgetWindow.ui->lineEdit_2->setText("100"); // Valid limit
    budgetWindow.ui->lineEdit_3->setText("200"); // Reminder > limit

    budgetWindow.onSaveClicked();
    EXPECT_TRUE(cBudget::budgetList.empty()); // No budget saved

    // Simulate valid inputs
    budgetWindow.ui->lineEdit_2->setText("200"); // Reminder <= limit
    budgetWindow.onSaveClicked();
    EXPECT_EQ(cBudget::budgetList.size(), 1);
}

TEST(vBudgetTest, DisplayBudgets) {
    // Simulate budget creation
    cBudget budgetWindow;
    budgetWindow.ui->lineEdit->setText("Rent");
    budgetWindow.ui->lineEdit_2->setText("1200");
    budgetWindow.ui->lineEdit_3->setText("1000");
    budgetWindow.onSaveClicked();

    // Verify display in vBudget
    vBudget viewBudget;
    QString displayedBudgets = viewBudget.ui->label_6->text();
    EXPECT_TRUE(displayedBudgets.contains("Rent"));
}

class MockObserver : public Observer {
public:
    MOCK_METHOD(void, update, (const std::string& message), (override));
};

TEST(cBudgetTest, NotifyObservers) {
    MockObserver mockObserver;
    BudgetCategory category;
    category.addObserver(&mockObserver);

    EXPECT_CALL(mockObserver, update(::testing::HasSubstr("New budget created")))
        .Times(1);

    cBudget budgetWindow;
    budgetWindow.budgetCategory = &category; // Inject mock category
    budgetWindow.ui->lineEdit->setText("Groceries");
    budgetWindow.ui->lineEdit_2->setText("500");
    budgetWindow.ui->lineEdit_3->setText("200");
    budgetWindow.onSaveClicked();
}


