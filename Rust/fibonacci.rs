fn fib(a:i32,b:i32)->i32{
    let c=a+b;
    if c>100
    {
        return c;
    }
    else
    {
        println!("{}",c);
        return fib(b,c);


    }



}



fn main(){
    println!("{}",fib(0,1));


}
