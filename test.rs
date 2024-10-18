fn main() {
    let mut my_string = String::from("Hello");
    
    // Get a raw pointer to the string's buffer
    let ptr = my_string.as_mut_ptr();
    let capacity = my_string.capacity(); // Get the current capacity of the string

    unsafe {
        // Intentionally write beyond the allocated length of the string
        for i in 0..capacity + 50 { // Trying to write 5 extra characters
            // This will likely lead to undefined behavior
            *ptr.add(i) = b'A' as u8; // Write 'A' characters
        }

        // Print the contents of the string buffer (may lead to undefined behavior)
        for i in 0..capacity + 5 {
            // Read from the pointer; this may access out-of-bounds memory
            print!("{}", *ptr.add(i));
        }
        println!(); // Newline for readability
    }
}
