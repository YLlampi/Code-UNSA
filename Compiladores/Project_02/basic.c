#define VARIABLE_TYPE char

typedef VARIABLE_TYPE (*peek_func)(VARIABLE_TYPE);
typedef void (*poke_func)(VARIABLE_TYPE, VARIABLE_TYPE);

void ubasic_init(const char *program);
void ubasic_run(void);
int ubasic_finished(void);