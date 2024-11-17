// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <condition_variable>

// using namespace std;

// int shared_data = 0;
// int readers_count = 0;
// mutex mtx;
// condition_variable cv;

// void writer() {
//     while (true) {
//         {
//             unique_lock<mutex> lock(mtx);
//             // Writing to the shared resource
//             shared_data++;
//             cout << "Writer writes: " << shared_data << endl;
//         }
//         cv.notify_all(); // Notify all waiting threads that data has been written
//         // Simulate some time for writing
//         this_thread::sleep_for(chrono::seconds(2));
//     }
// }

// void reader() {
//     while (true) {
//         {
//             unique_lock<mutex> lock(mtx);
//             while (readers_count > 0) {
//                 cv.wait(lock); // Wait until all writers finish writing
//             }
//             readers_count++;
//         }
//         // Reading from the shared resource
//         cout << "Reader reads: " << shared_data << endl;
//         {
//             unique_lock<mutex> lock(mtx);
//             readers_count--;
//         }
//         // Simulate some time for reading
//         this_thread::sleep_for(chrono::seconds(1));
//     }
// }

// int main() {
//     thread writer_thread(writer);
//     thread reader_thread(reader);

//     writer_thread.join();
//     reader_thread.join();

//     return 0;
// }
