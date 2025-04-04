import csv
import sys

def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py STR DNA-sequence database")
        sys.exit(1)
    

    # TODO: Read database file into a variable
    head = None
    rows = []
    with open(sys.argv[1]) as database:
        reader_db = csv.DictReader(database)
        head = (reader_db.fieldnames)
        for row in reader_db:
            rows.append(row)
    print("head:",head)
    print("rows:",rows)


    # TODO: Read DNA sequence file into a variable
    sequence = ""
    with open(sys.argv[2]) as seq:
        reader_seq = csv.DictReader(seq)
        sequence = reader_seq.fieldnames[0]
    print("sequence:",sequence)

    # TODO: Find longest match of each STR in DNA sequence
    longests = []
    for i in range(1, len(head)):
        longests.append(longest_match(sequence, head[i])) 
        # print(f"head {i}: {head[i]}")
        print("longest: ",longests)

    # TODO: Check database for matching profiles
    for i in range(len(rows)):
        print(f"rows {i}: {rows[i]}")
        correct = 0
        name = ""
        for j in range(1, len(head)):
            print(f"head {j}: {head[j]}")
            print(f"rows {i}: {rows[i][head[j]]}")
            print(f"longest {j}: {longests[j-1]}")
            print("true ?", int(longests[j-1]) == int(rows[i][head[j]]))
            if int(longests[j-1]) == int(rows[i][head[j]]):
                correct += 1
                if correct == len(head) - 1:
                    name = rows[i]["name"]
                    print(f"{name}.")
                    return
            else:
                break
    print("No match.")
    return


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
