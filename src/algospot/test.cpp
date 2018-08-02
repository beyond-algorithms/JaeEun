#include <cstdio>
#include <string>

const char* a() {
    std::string mystr("abc");

	save = mystr;
	
    return mystr.c_str();
}
int main() {
    const char* cptr = a();

    printf("%s", cptr);  /// what happen?
    printf("%s", save.c_str());  /// what happen?
	
    return 0;
}
