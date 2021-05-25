use std::net::UdpSocket;
//use std::time::{Instant, SystemTime, UNIX_EPOCH};
use std::time::Instant;

fn main() -> std::io::Result<()> {
    {
        let socket = UdpSocket::bind("127.0.0.1:8989")?;

        let data = String::from("I'm RUST!");
        //let mut count = 0;

        let start = Instant::now();
        let mut n = start.elapsed().as_nanos();

        /*
        let sys_start = SystemTime::now();
        let since_the_epoch = sys_start.duration_since(UNIX_EPOCH)
            .expect("Time went backwards");
        let ss = since_the_epoch.as_secs(); 
        std::println!("last time: {}, elapsed: {}", ss, n);
        */
        std::println!(" elapsed: {}", n);

        //loop {
        for _i in 1..100001 {
            socket.send_to(data.as_bytes(), "127.0.0.1:9998")?;

            /*
            count = count+1;
            n = start.elapsed().as_nanos();
            if n >= 1000000000 {
                 println!("elapsed : {}, count:{}", n, count);
                 break
            } 
            */
        }

        /*
        let end = SystemTime::now();
        let end_since_the_epoch = end.duration_since(UNIX_EPOCH)
            .expect("Time went backwards");
        let es = end_since_the_epoch.as_secs();
        std::println!("crurent time: {}", es);
        */
        n = start.elapsed().as_nanos();
        println!("elapsed : {}", n);
    }
    Ok(())
}

