//https://github.com/sol2namu/BOJ/new/master

#define MAX 101

char stack[MAX];
int top=-1;

char front(){
	return stack[top];
}

void push(char data){
	stack[++top] = data;
}

char pop(){
	return stack[top--];
}

int empty(){
	if (top == -1) return 1;
	return 0;
}


int oper(char op){
	if (op == '(') return 0;
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
}

int main(){
	string c;
	cin >> c;

	int len = c.length();
	for (int i = 0; i < len; i++){
		if ('A' <= c[i] && c[i] <= 'Z'){
			cout << c[i];
		}
		else{
			if (c[i] == ')') {
				while (!empty()){
					char data = pop();
					if (data == '(') break;
					cout << data;
				}
			}
			else if (c[i] == '('){
				push(c[i]);
			}
			else{
				if (empty()){
					push(c[i]);
				}
				else{
					int cur = oper(c[i]);
					char data = front();
					int stp = oper(data);

					if (cur > stp){
						push(c[i]);
					}
					else{
						while (!empty()){
							data = front();
							stp = oper(data);

							if (cur > stp) break;
							cout << data;
							pop();
						}
						push(c[i]);
					}
				}
			}
		}
	}
	while (!empty()) cout << front(), pop();
}
