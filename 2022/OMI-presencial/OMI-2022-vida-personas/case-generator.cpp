#include <stdlib.h>

#include <algorithm>
#include <experimental/random>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

struct RangeConstraint {
  int lower_limit;
  int upper_limit;
};

namespace random {

int randBetween(int lower_limit, int upper_limit) {
  return std::experimental::randint(lower_limit, upper_limit);
}

int randBetween(RangeConstraint constraint) {
  return randBetween(constraint.lower_limit, constraint.upper_limit);
}

bool randDecision() { return (!(rand() % 2 == 0)); }

std::vector<int> generateRandomOrder(int size) {
  std::vector<int> order;
  for (int number = 1; number <= size; number++) {
    order.push_back(number);
  }
  std::random_shuffle(order.begin(), order.end());
  return order;
}

std::vector<int> generateArray(int size, int lower_limit, int upper_limit) {
  std::vector<int> numbers;
  for (int i = 0; i < size; i++) {
    numbers.push_back(randBetween(lower_limit, upper_limit));
  }
  return numbers;
}

std::vector<int> generateArray(int size, RangeConstraint constraint) {
  return generateArray(size, constraint.lower_limit, constraint.upper_limit);
}

std::vector<std::pair<int, int>> generateArrayRangeQueries(
    int number_of_queries, int array_size, bool one_indexed = false) {
  std::vector<std::pair<int, int>> queries;

  int lower_limit = (one_indexed) ? 1 : 0;
  int upper_limit = array_size;

  for (int i = 0; i < number_of_queries; i++) {
    int left_index = randBetween(lower_limit, upper_limit);
    int right_index = randBetween(left_index, upper_limit);
    queries.push_back(std::make_pair(left_index, right_index));
  }

  return queries;
}

std::vector<std::pair<int, int>> generateRanges(
    int number_of_ranges, RangeConstraint constraint,
    bool zero_size_allowed = false) {
  std::vector<std::pair<int, int>> ranges;

  int lower_limit = constraint.lower_limit;
  int upper_limit = constraint.upper_limit;

  for (int i = 0; i < number_of_ranges; i++) {
    int left_index = randBetween(lower_limit, upper_limit);
    int right_index = randBetween(left_index, upper_limit);
    ranges.push_back(std::make_pair(left_index, right_index));
  }

  return ranges;
}

};  // namespace random

class FileWriter {
 public:
  FileWriter(std::string output_filename) : ofstream_(output_filename) {}

  template <typename T>
  void write(T value, char separator) {
    if constexpr (std::is_same_v<std::decay_t<T>, int>) {
      writeInt(value, separator);
    } else if constexpr (std::is_same_v<std::decay_t<T>, std::vector<int>>) {
      writeVectorInt(value, " ", separator);
    } else if constexpr (std::is_same_v<std::decay_t<T>,
                                        std::vector<std::pair<int, int>>>) {
      writeVectorPair(value, " ", separator);
    } else if constexpr (std::is_same_v<std::decay_t<T>, std::string>) {
      writeString(value, separator);
    }
  }

  template <typename T>
  void write(T value, char middle_separator, char end_separator) {
    if constexpr (std::is_same_v<std::decay_t<T>, int>) {
      writeInt(value, end_separator);
    } else if constexpr (std::is_same_v<std::decay_t<T>, std::vector<int>>) {
      writeVectorInt(value, middle_separator, end_separator);
    } else if constexpr (std::is_same_v<std::decay_t<T>,
                                        std::vector<std::pair<int, int>>>) {
      writeVectorPair(value, middle_separator, end_separator);
    } else if constexpr (std::is_same_v<std::decay_t<T>, std::string>) {
      writeString(value, end_separator);
    }
  }

  ~FileWriter() { ofstream_.close(); }

 private:
  void writeInt(int value, char end_separator) {
    ofstream_ << value << end_separator;
  }

  void writeVectorInt(std::vector<int> values, char middle_separator,
                      char end_separator) {
    for (int i = 0; i < values.size(); i++) {
      if (i > 0) {
        ofstream_ << middle_separator;
      }
      ofstream_ << values[i];
    }
    ofstream_ << end_separator;
  }

  void writeVectorPair(std::vector<std::pair<int, int>> values,
                       char middle_separator, char end_separator) {
    for (int i = 0; i < values.size(); i++) {
      if (i > 0) {
        ofstream_ << middle_separator;
      }
      ofstream_ << values[i].first << " " << values[i].second;
    }
    ofstream_ << end_separator;
  }

  void writeString(std::string message, char end_separator) {
    ofstream_ << message << end_separator;
  }

  std::ofstream ofstream_;
};

class SubtaskInfo {
 public:
  SubtaskInfo(std::string name, int points, int number_of_tests)
      : name_(name), points_(points), number_of_tests_(number_of_tests) {}

  void addRangeConstraint(std::string variable_name, int lower_limit,
                          int upper_limit) {
    RangeConstraint constraint = {lower_limit, upper_limit};
    constraints_[variable_name] = constraint;
  }

  std::map<std::string, RangeConstraint> constraints() { return constraints_; }

  int points() { return points_; }

  int number_of_tests() { return number_of_tests_; }

 private:
  std::string name_;
  int number_of_tests_;
  int points_;
  std::map<std::string, RangeConstraint> constraints_;
};

class CustomGeneratorBase {
 public:
  CustomGeneratorBase() {}

  virtual void generate() {}

  void setRangeConstraints(
      const std::map<std::string, RangeConstraint>& constraints) {
    constraints_ = constraints;
  }

  void setFileWriter(FileWriter* file_writer) { file_writer_ = file_writer; }

  RangeConstraint getConstraint(std::string variable) {
    return constraints_[variable];
  }

  virtual ~CustomGeneratorBase() {}

 protected:
  template <typename T>
  void write(T value, char separator) {
    file_writer_->write(value, separator);
  }

  template <typename T>
  void write(T value, char middle_separator, char end_separator) {
    file_writer_->write(value, middle_separator, end_separator);
  }

 private:
  std::map<std::string, RangeConstraint> constraints_;
  FileWriter* file_writer_;
};

class TestGenerator {
 public:
  TestGenerator(CustomGeneratorBase* custom_generator, std::string path,
                std::string subtask_name_prefix, std::string separator,
                std::string test_name_prefix, bool grouped_cases)
      : custom_generator_(custom_generator),
        subtask_name_prefix_(subtask_name_prefix),
        separator_(separator),
        path_(path),
        test_name_prefix_(test_name_prefix),
        grouped_cases_(grouped_cases),
        testplan_("testplan") {}

  void addSubtask(SubtaskInfo subtask) { subtasks_.push_back(subtask); }

  void generate() {
    int current_subtask = 1;
    int current_global_test_number = 1;

    for (SubtaskInfo subtask : subtasks_) {
      custom_generator_->setRangeConstraints(subtask.constraints());
      for (int i = 0; i < subtask.number_of_tests(); i++) {
        int current_test_number = i + 1;
        std::string output_filename =
            getTestFilename(current_subtask, current_test_number,
                            /* include_path = */ true,
                            /* include_extension = */ true);

        std::cout << "Generating " << output_filename << std::endl;
        FileWriter* file_writer = new FileWriter(output_filename);

        if (grouped_cases_) {
          int test_points = (current_test_number == 1) ? subtask.points() : 0;
          writeToTestplan(current_subtask, current_test_number, test_points);
        }

        custom_generator_->setFileWriter(file_writer);
        custom_generator_->generate();
        delete file_writer;
      }

      current_subtask++;
    }
  }

  ~TestGenerator() { generate(); }

 private:
  std::string getTestFilename(int subtask_number, int test_number,
                              bool include_path, bool include_extension) {
    std::string filename = subtask_name_prefix_ +
                           std::to_string(subtask_number) + separator_ +
                           test_name_prefix_ + std::to_string(test_number);

    if (include_extension) {
      filename += ".in";
    }

    if (include_path) {
      return path_ + filename;
    }
    return filename;
  }

  void writeToTestplan(int subtask_number, int test_number, int points) {
    std::string output_filename =
        getTestFilename(subtask_number, test_number,
                        /* include_path = */ false,
                        /* include_extension = */ false);

    testplan_.write(output_filename, ' ');
    if (test_number == 1) {
      testplan_.write(points, '\n');
    } else {
      testplan_.write(0, '\n');
    }
  }

  std::string path_;
  std::string subtask_name_prefix_;
  std::string separator_;
  std::string test_name_prefix_;
  std::vector<SubtaskInfo> subtasks_;
  bool grouped_cases_;
  FileWriter testplan_;
  CustomGeneratorBase* custom_generator_;
};

// La generacion especifica del problema se implementa a partir de esta linea

class VidaDeLasPersonasGenerator : public CustomGeneratorBase {
 public:
  void generate() {
    int n = random::randBetween(getConstraint("n"));
    write(n, ' ');

    int q = random::randBetween(getConstraint("q"));
    write(q, '\n');

    std::vector<std::pair<int, int>> year_ranges = random::generateRanges(
        /* number of ranges  = */ n,
        /* range_constraint  = */ getConstraint("year_ranges"),
        /* zero_size_allowed = */ false);
    write(year_ranges, '\n', '\n');

    std::vector<int> year_queries = random::generateArray(
        /* size             = */ q,
        /* range_constraint = */ getConstraint("year_ranges"));
    write(year_queries, '\n', '\n');
  }
};

int main() {
  TestGenerator test_generator(
      /* custom_generator =    */ new VidaDeLasPersonasGenerator,
      /* path =                */ "cases/",
      /* subtask_name_prefix = */ "sub",
      /* separator =           */ ".",
      /* test_name_prefix =    */ "",
      /* grouped_cases =       */ true);

  // Subtask 1: N, Q, a_i, b_i <= 1000
  SubtaskInfo subtask1(/* name = */ "subtask1",
                       /* points = */ 12,
                       /* number_of_tests = */ 5);

  subtask1.addRangeConstraint(/* variable_name = */ "n",
                              /* lower_limit =   */ 1,
                              /* upper_limit =   */ 1000);

  subtask1.addRangeConstraint(/* variable_name = */ "q",
                              /* lower_limit =   */ 1,
                              /* upper_limit =   */ 1000);

  subtask1.addRangeConstraint(/* variable_name = */ "year_ranges",
                              /* lower_limit =   */ 1,
                              /* upper_limit =   */ 1000);

  // Subtask 2: N, a_i, b_i <= 1000, Q <= 10^4
  SubtaskInfo subtask2(/* name = */ "subtask2",
                       /* points = */ 24,
                       /* number_of_tests = */ 5);

  subtask2.addRangeConstraint(/* variable_name = */ "n",
                              /* lower_limit =   */ 1,
                              /* upper_limit =   */ 1000);

  subtask2.addRangeConstraint(/* variable_name = */ "q",
                              /* lower_limit =   */ 9000,
                              /* upper_limit =   */ 10000);

  subtask2.addRangeConstraint(/* variable_name = */ "year_ranges",
                              /* lower_limit =   */ 1,
                              /* upper_limit =   */ 1000);

  // Subtask 3: N, a_i, b_i <= 10^6, Q <= 10^4
  SubtaskInfo subtask3(/* name = */ "subtask3",
                       /* points = */ 27,
                       /* number_of_tests = */ 5);

  subtask3.addRangeConstraint(/* variable_name = */ "n",
                              /* lower_limit =   */ 300000,
                              /* upper_limit =   */ 1000000);

  subtask3.addRangeConstraint(/* variable_name = */ "q",
                              /* lower_limit =   */ 9000,
                              /* upper_limit =   */ 10000);

  subtask3.addRangeConstraint(/* variable_name = */ "year_ranges",
                              /* lower_limit =   */ 1,
                              /* upper_limit =   */ 1000000);

  // Subtask 4: N, Q <= 10^6, a_i, b_i <= 10^9
  SubtaskInfo subtask4(/* name = */ "subtask4",
                       /* points = */ 37,
                       /* number_of_tests = */ 5);

  subtask4.addRangeConstraint(/* variable_name = */ "n",
                              /* lower_limit =   */ 300000,
                              /* upper_limit =   */ 1000000);

  subtask4.addRangeConstraint(/* variable_name = */ "q",
                              /* lower_limit =   */ 300000,
                              /* upper_limit =   */ 1000000);

  subtask4.addRangeConstraint(/* variable_name = */ "year_ranges",
                              /* lower_limit =   */ 1,
                              /* upper_limit =   */ 1000000000);

  test_generator.addSubtask(subtask1);
  test_generator.addSubtask(subtask2);
  test_generator.addSubtask(subtask3);
  test_generator.addSubtask(subtask4);

  // test_generator goes out of scope and generate() is called
  return 0;
}