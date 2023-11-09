#ifndef PASSWORD_CHECKER_H
#define	PASSWORD_CHECKER_H

// Interfaces.
char *input_password_interface();
void print_result_interface(int health);

// Business logics.
int check_password_health(char *password);

#endif	/* PASSWORD_CHECKER_H */

