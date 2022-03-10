package main

import "fmt"

func main() {
	var a complex128
	a = 3.14 + 2.14i
	fmt.Println("a=", a)

	t := 3.4 + 73.7i
	fmt.Println("t=", t)
	fmt.Printf("%T\n", t)

	fmt.Println("real=", real(t), ",imag=", imag(t))
}
