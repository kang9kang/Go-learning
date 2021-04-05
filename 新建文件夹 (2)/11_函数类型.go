package main

import "fmt"

func add(a, b int) int {
	return a + b
}

func minus(a, b int) int {
	return a - b
}

type ftest func(int, int) int

func main() {
	var result int
	result = add(1, 2)
	fmt.Println("result=", result)
	result = minus(2, 1)
	fmt.Println("result=", result)

	var f ftest
	f = add
	result = f(10, 20)
	fmt.Println("result=", result)
	f = minus
	result = f(10, 20)
	fmt.Println("result=", result)
}
