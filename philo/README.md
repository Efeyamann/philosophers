# 🧘 Philosophers

This project is a simulation of the classic **Dining Philosophers** problem, focusing on concurrency, synchronization, and avoiding deadlocks.

Each philosopher alternates between thinking, eating, and sleeping. To eat, they need two forks (shared with neighbors), and the challenge is to manage this without causing race conditions or deadlocks.

## 💡 Key Points

- Implemented using threads and mutexes (pthreads)
- Avoids deadlocks and starvation
- Handles timing for eating, sleeping, and dying
- Optional argument to stop when all philosophers have eaten a set number of times
