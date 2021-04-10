package main

import "fmt"

func test() (a, b, c int) {
	return 1, 2, 3
}
func main() {
	a, b := 10, 20
	fmt.Println("a=", a)
	fmt.Printf("b=%d\n", b)
	a, b = b, a
	fmt.Println("a=", a)
	fmt.Printf("b=%d\n", b)
	var c, d, e int
	_, d, _ = test()
	fmt.Printf("c=%d,d=%d,e=%d\n", c, d, e)
	_, d, e = test()
	fmt.Printf("c=%d,d=%d,e=%d\n", c, d, e)
	c, d, e = test()
	fmt.Printf("c=%d,d=%d,e=%d\n", c, d, e)
}
