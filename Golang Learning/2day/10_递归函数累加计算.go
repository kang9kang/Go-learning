package main

import "fmt"

func sum(a int) (result int) {

	if a == 1 {
		return 1
	}

	result = a + sum(a-1)
	return
}

func main() {
	b := sum(100)
	fmt.Println("b=", b)
}
