int division_method(int val, int size_table);
int fold_method(int val, int n);
int multiplication_method(double val, int size_table);
// void digits_analysys_method(int val, int size_table);

int count_digits(int value);
int sum_digits(int a, int b);

void add_vector(int *vec, int key, int size);
int fold(int *vector, int size);

void division_method_tests(int *keys, int n, int solves_collision);
void multiplication_method_tests(int *keys, int n, int solves_collision);
void fold_method_tests(int *keys, int n);

void fill_vector_hash(int n, int *vector);