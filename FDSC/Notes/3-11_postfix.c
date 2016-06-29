/* code list 3-11_postfix.c */
void postfix(void)
{
    /* output the postfix of the expression. 
    The expression string, the stack, and top
    are global. */
    char symbol;
    precedence token;
    int n = 0;
    int top = 0; // place eos on stack
    stack[0] = eos;
    for (token = get_token(&symbol, &n); token != eos;
        token = get_token(&symbol, &n))
    {
        if (token == operand)
            printf("%c", symbol);
        else if (token == rparen)
        {
            // unstack tokens until left parenthesis
            while (stack[top] != lparen)
                print_token(delete(&top));
            delete(&top); // discard left parenthesis
        }
        else
        {
            /* remove and print symbols whose isp is 
            greater than or equal to current token's icp */
            while (isp[stack[top]] >= icp[token])
                print_token(delete(&top));
            add(&top, token);
        }    
    }
    while ((token = delete(&top)) != eos)
        print_token(token);
    printf("\n");
}