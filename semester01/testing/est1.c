#include <stdio.h>

double do_sqrt(double target){
	double ans = target, error = 0.000001;
	while(ans-target/ans>error){
		ans = (ans+target/ans)/2;
	}
	return ans;
}

int main(){
	double target_input;
	printf("sqrt target: ");
	scanf("%lf", &target_input);
	printf("%lf\n", do_sqrt(target_input));
	return 0;
}