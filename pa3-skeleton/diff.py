# python
for i in range(13, 31):
    # Open File in Read Mode
    file_name_example = "output" + str(i) + ".txt"
    file_name2_output = "output_" + str(i) + ".txt"
    file_directory_example = (
        "C:/Users/zhiyi/OneDrive/Documents/GitHub/COMP2012H/pa3_skeleton/output_example/"
        + file_name_example
    )
    file_directory_output = (
        "C:/Users/zhiyi/OneDrive/Documents/GitHub/COMP2012H/pa3_skeleton/output/"
        + file_name2_output
    )
    file_1 = open(file_directory_example, "r")
    file_2 = open(file_directory_output, "r")

    print(
        "Comparing files ",
        " @ " + file_name_example,
        " # " + file_name2_output,
        sep="\n",
    )

    file_1_line = file_1.readline()
    file_2_line = file_2.readline()

    # Use as a COunter
    line_no = 1

    print()

    with open(file_directory_example) as file1:
        with open(file_directory_output) as file2:
            same = set(file1).intersection(file2)

    print("Common Lines in Both Files")

    for line in same:
        print(line, end="")

    print("\n")
    print("Difference Lines in Both Files")
    while file_1_line != "" or file_2_line != "":

        # Removing whitespaces
        file_1_line = file_1_line.rstrip()
        file_2_line = file_2_line.rstrip()

        # Compare the lines from both file
        if file_1_line != file_2_line:

            # otherwise output the line on file1 and use @ sign
            if file_1_line == "":
                print("@", "Line-%d" % line_no, file_1_line)
            else:
                print("@-", "Line-%d" % line_no, file_1_line)

            # otherwise output the line on file2 and use # sign
            if file_2_line == "":
                print("#", "Line-%d" % line_no, file_2_line)
            else:
                print("#+", "Line-%d" % line_no, file_2_line)

            # Print a empty line
            print()

        # Read the next line from the file
        file_1_line = file_1.readline()
        file_2_line = file_2.readline()

        line_no += 1

    file_1.close()
    file_2.close()
