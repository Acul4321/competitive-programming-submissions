use proconio::input;

fn main() {
    input! {
        q: i32,
        a: [String;q],
    }
    
    let mut iter = a.iter();
    println!("{}", iter);
    //println!("Hello World")
}