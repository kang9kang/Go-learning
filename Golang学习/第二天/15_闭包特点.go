package main

import "fmt"

func test02() func() int {
	var x int
	return func() int {
		x++
		return x * x
	}
}

func main() {
	f := test02()
	fmt.Println(f())
	fmt.Println(f())
	fmt.Println(f())
	fmt.Println(f())
	fmt.Println(f())
}

func test01() int {
	//函数调用时x才会分配空间，初始化为0
	var x int
	x++
	return x * x //结束函数，释放x
}

func main01() {
	fmt.Println(test01())
	fmt.Println(test01())
	fmt.Println(test01())
	fmt.Println(test01())
	fmt.Println(test01())
}
