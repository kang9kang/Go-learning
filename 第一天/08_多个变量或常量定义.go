package main

import "fmt"

func main() {
	// var (
	// 	a int
	// 	b float64
	// )
	// a, b = 10, 10.4
	// fmt.Printf("a=%d,b=%f", a, b)
	const (
		i = 10
		j = 12.4
	)
	fmt.Printf("i=%T,j=%T\n", i, j)
}
