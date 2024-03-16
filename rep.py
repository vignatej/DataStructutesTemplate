file_path = 'rep.txt'  # Replace with the actual path to your file

# Read the file
with open(file_path, 'r') as file:
    content = file.read()

# Replace '[' with '{'
content = content.replace('[', '{')

# Replace ']' with '}'
content = content.replace(']', '}')

# Write the modified content back to the file
with open(file_path, 'w') as file:
    file.write(content)
print("uttd")