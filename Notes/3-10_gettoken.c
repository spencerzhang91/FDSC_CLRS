/* code list 3-10_gettoken.c */
precedence get_token(char *symbol, int *n)
{
    /* get the next token, symbol is the 
    character representaion, which is returned,
    the token is represented by its enumerated
    value, which is returned in the function name */
    *symbol = expr[(*n)++];
    switch (*symbol)
    {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case ' ': return eos;
        default : return operand;
    }
}