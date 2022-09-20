#define VARIABLE_TYPE char

typedef VARIABLE_TYPE (*peek_func)(VARIABLE_TYPE);
typedef void (*poke_func)(VARIABLE_TYPE, VARIABLE_TYPE);

void ubasic_init(const char *program);
void ubasic_run(void);
int ubasic_finished(void);

VARIABLE_TYPE ubasic_get_variable(int varnum);
void ubasic_set_variable(int varum, VARIABLE_TYPE value);

