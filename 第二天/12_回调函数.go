package main

import "fmt"

type functype func(int, int) int

func add(a, b int) int {
	return a + b
}

func minus(a, b int) int {
	return a - b
}

func mul(a, b int) int {
	return a * b
}

func Calc(a, b int, ftest functype) (result int) {
	fmt.Println("Calc")
	result = ftest(a, b)

	return
}

func main() {
	result := Calc(10, 20, add)
	fmt.Println("result=", result)
	result = Calc(10, 20, minus)
	fmt.Println("result=", result)
	result = Calc(10, 20, mul)
	fmt.Println("result=", result)
}
