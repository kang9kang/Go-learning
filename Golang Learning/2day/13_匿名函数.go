package main

import "fmt"

func main() {
	a := 10
	str := "mike"
	//匿名函数 只有定义
	f1 := func() {
		fmt.Println("a=", a)
		fmt.Println("str=", str)
	}
	//匿名函数调用
	f1()
	//给一个函数起别名
	type functype func()
	//声明变量
	var f2 functype
	f2 = f1
	f2()

	//定义匿名函数的同时调用函数
	func() {
		fmt.Println("a=", a)
		fmt.Println("str=", str)
	}() //后面的()代表调用

	//带参数的匿名函数
	f3 := func(i, j int) {
		fmt.Printf("i=%d,j=%d\n", i, j)
	}
	f3(10, 20)
	//匿名函数的定义加调用
	func(i, j int) {
		fmt.Printf("i=%d,j=%d\n", i, j)
	}(10, 20)

	x, y := func(i, j int) (max, min int) {
		if i > j {
			max = i
			min = j
		} else {
			max = j
			min = i
		}
		return
	}(10, 20)

	fmt.Printf("x=%d,y=%d\n", x, y)

}
