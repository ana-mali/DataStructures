#ifndef A5_H_
#define A5_H_

# define MAX 200
# define True 1
# define False 0

void get_file_stats(const char *in_file, const char *out_file);
void format_file1(const char *in_file, const char *out_file);
void format_file2(const char *in_file, const char *out_file);
void filter_by_area(const char *in_file, const char *out_file, float area_threshold);
void replace_two_chars(const char *filename, char *str1, char* str2);

#endif /* A5_H_ */
