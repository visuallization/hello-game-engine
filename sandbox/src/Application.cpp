namespace Hello {
	__declspec(dllimport) void Print();
}

void main() {
	Hello::Print();
}