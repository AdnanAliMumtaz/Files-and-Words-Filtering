## Classes and Methods

### File Class

The `File` class handles reading text files, storing words, and counting word frequencies.

#### Constructor

- **File(string txtname)**: Initializes an instance by reading the specified text file (`txtname`) and populates `textWords` with its contents.

#### Methods

- **Writefile(string name, vector<string> textwords)**: Writes the contents of `textwords` to a file named `name`.

- **FrequencyCounter(vector<string> FrequencyWord)**: Counts the frequency of words in `FrequencyWord`. Converts words to lowercase, removes punctuation, and counts occurrences.

---

### Comparison Class

The `Comparison` class extends the `File` class to compare text files against a list of banned words and filter them accordingly.

#### Constructor

- **Comparison(string txt)**: Inherits from `File` and initializes by reading and processing the text file specified by `txt`.

#### Methods

- **comparison(vector<string> banned_Words, vector<string> textFile, string FilterFile)**: Compares `textFile` with `banned_Words`, replacing occurrences of banned words with asterisks in `FilterFile`.

---

### Sorting and Output

After processing, the program outputs the top 10 most frequent words in each text file and writes all processed words to `sorted.txt`.































# Text File Analysis and Filtering

This C++ project analyzes multiple text files, counts word frequencies, filters out banned words, and outputs the results to new files. It's designed for efficient file handling and text processing.

## Project Overview

### Components

1. **File Class**: Handles reading text files (`text1.txt`, `text2.txt`, etc.), storing words, and counting word frequencies.
  
2. **Comparison Class**: Extends `File` to compare text files against a list of banned words, replacing occurrences of banned words with asterisks in filtered text.

3. **Sorting and Output**: After processing, the program outputs the top 10 most frequent words in each text file and writes all processed words to `sorted.txt`.

## Classes and Methods

### File Class

#### Constructor

- **File(string txtname)**: Initializes by reading `txtname`, storing words in `textWords`.

#### Methods

- **Writefile(string name, vector<string> textwords)**: Writes `textwords` to file `name`.

- **FrequencyCounter(vector<string> FrequencyWord)**: Counts word frequencies, handling lowercase conversion and punctuation removal.

### Comparison Class

#### Constructor

- **Comparison(string txt)**: Inherits `File`, reads and processes `txt`.

#### Methods

- **comparison(vector<string> banned_Words, vector<string> textFile, string FilterFile)**: Compares `textFile` with `banned_Words`, replacing banned words with asterisks in `FilterFile`.

### Sorting and Output

- Outputs top 10 most frequent words and their counts for each text file.
- Writes all processed and sorted words to `sorted.txt`.

## Usage

1. **Compile**: Use a C++ compiler (C++11 or higher).
   
2. **Execution**: Run the compiled program. It reads `banned.txt`, `text1.txt`, `text2.txt`, `text3.txt`, `text4.txt`, filters banned words, and outputs to `text1Filtered.txt`, `text2Filtered.txt`, `text3Filtered.txt`, `text4Filtered.txt`, and `sorted.txt`.

## Example Output

- Displays top 10 words and frequencies.
- Shows occurrences of banned words.
- Generates filtered text files and `sorted.txt` with processed words.

## Screenshots
<img width="1236" alt="Screenshot 2024-06-19 at 8 16 00 PM" src="https://github.com/AdnanAliMumtaz/Files-and-Words-Filtering/assets/81415901/c387c88d-e44f-4c0f-8738-869eb110926c">



## Dependencies

- C++ Standard Library (`iostream`, `fstream`, `sstream`, `vector`)

Ensure your environment supports these standard libraries for compilation and execution.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.
