from csv import DictReader, reader
import sys

def substring_max_frequency(DNA_sequence, substring):
    
    frequency = [0] * len(DNA_sequence)
    for i in range(len(DNA_sequence) - len(substring), -1, -1): 
        if DNA_sequence[i: i + len(substring)] == substring:
            if i + len(substring) > len(DNA_sequence) - 1: 
                frequency[i] = 1
            else:
                frequency[i] = 1 + frequency[i + len(substring)]
    return max(frequency)
    
    
def print_matching(database, actual_array):
    for row in database:
        individual = row[0]
        values = [ int(val) for val in row[1:] ]
        if values == actual_array: 
            print(individual)
            return 
    print("No match found")
    
    
def main():
    # Valid Input
    if len(sys.argv) != 3:
        print("Error")
        sys.exit("Usage: python tournament.py FILENAME")
    
    # Read CSV file into memory 
    csv_file_path = sys.argv[1]
    with open (csv_file_path) as csv_file:
        database = reader(csv_file)
        entire_sequence = next(database)[1:]
    
    # Read DNA sequences into memory
        txt_file_path = sys.argv[2]
        with open (txt_file_path) as txt_file:
            # File contents converted into string
            DNA_sequence = txt_file.read()
            actual_array = [substring_max_frequency(DNA_sequence, sequence) for sequence in entire_sequence]
        
        print_matching(database, actual_array)



if __name__ == "__main__":
    main()




