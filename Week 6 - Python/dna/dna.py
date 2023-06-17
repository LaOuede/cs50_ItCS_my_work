import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage : python dna.py <file.csv> <file.txt>")

    # TODO: Read database file into a variable
    database = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for person in reader:
            database.append(person)

    # TODO: Read DNA sequence file into a variable
    txt = open(sys.argv[2], "r")
    dna = txt.read()

    # TODO: Find longest match of each STR in DNA sequence
    # Extract informations from header but only the sequences not the column name
    header = list(database[0].keys())[1:]
    # Put values in a tab
    tab_res = {}
    for value in header:
        tab_res[value] = longest_match(dna, value)

    # TODO: Check database for matching profiles
    found = 0
    for person in database:
        match = 0
        for value in tab_res:
            if int(person[value]) == tab_res[value]:
                match += 1
        if match == len(header):
            name = person["name"]
            found = 1

    if found == 0:
        print("No match")
    else:
        print(name)


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
