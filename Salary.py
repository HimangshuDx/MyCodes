
basic_salary = float(input("Enter Basic Salary: "))
da = float(input("Enter Dearness Allowance (DA): "))
hra = float(input("Enter House Rent Allowance (HRA): "))
tax = float(input("Enter Tax Deducted: "))

gross_salary = basic_salary + da + hra
net_salary = gross_salary - tax

print(f"Gross Salary: {gross_salary}")
print(f"Net Salary: {net_salary}")
