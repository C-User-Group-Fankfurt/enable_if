# Fourth C++ User Group Frankfurt Meetup 🥳

* templates in C++ are **hard** to understand
* the best practice changes from standard to standard
* in automotive we are stuck to C++14
  * if we are lucky we have C++17
* Copilot just guesses (often wrong)
* even Stackoverflow is not always helpful
* learning the concepts behind the implementation safes us hopefully one or two Google searches

---

# Type Traits and std::enable_if

In this Meetup we will:
* learn about Substitution Failure is not an Error (SFINAE)
* implement a simple type trait
* activate type dependent template specializations using `std::enable_if`
* simplify the example using *_v and *_t
* reduce the boilerplate code by some clever template programming

---

## Scope
* C++14
* understand the logic behind it

## Out of Scope
* C++17 and later
* constraints and concepts from C++20

---

## Hands-On Coding - no slides

* I'm Daniel
* please ask questions right away
* this is a real world example from our daily work

---

## Resources

* [C++ Template Specialization Using Enable If](https://leimao.github.io/blog/CPP-Enable-If/)
* [What is the purpose of _t aliases and _v variable templates for type traits?](https://stackoverflow.com/questions/77083721/what-is-the-purpose-of-t-aliases-and-v-variable-templates-for-type-traits)
* [Standard library header <type_traits>](https://en.cppreference.com/w/cpp/header/type_traits)

---

# Build

```bash
sudo apt install python3-venv
python3 -m venv ~/python/pre-commit
source ~/python/pre-commit/bin/activate
pip install -r requirements.txt
pre-commit install
```
