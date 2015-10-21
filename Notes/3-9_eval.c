/* code list 3-9_eval.c */
int eval(void)
{
    precedence token;
    char symbol;
    int op1, op2;
    int n = 0; // counter for the expression string
    int top = -1;
    token = get_token(&symbol, &n);
    while (token != eos)
    {
        if (token == operand)
            add(&top, symbol - '0'); // stack insert
        else
        {
            /* remove two operands, perform operation, and return
            result to the stack */
            op2 = delete(&top);
            op1 = delete(&top);
            switch(token)
            {
                case plus: add(&top, op1 + op2); break;
                case minus: add(&top, op1 - op2); break;
                case times: add(&top, op1 * op2); break;
                case divide: add(&top, op1 / op2); break;
                case mod: add(&top, op1 % op2); break;
                default printf("Someting wrong!\n");
            }
        }
        token = get_token(&simbol, &n);
    }
    return delete(&top); // return result
}