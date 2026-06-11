## iblang

> ℹ️NOTE: For the self hosted version see: [branch: ib](https://github.com/Luminighty/iblang/tree/ib)
> There are no new features planned for this branch, as the self-hosted version is currently getting built.

```iblang
const stdlib = import "stdlib"

fn main(): int {
  stdlib::printf("Hello, Iblang!\n");
  return 0;
}
```


```iblang
const stdlib = import "stdlib"

fn add(a: int, b: int): int {
  return a + b;
}

fn builtin_types() {
  let n: int = 10;
  let c: char = 'a';
  let b: bool = true;
  let f: float = 10.2;
  let y = 20;
  let z: int = n + f;
  stdlib::printf("x + y = %d\n", z);
}

fn loops() {
  let arr = [1, 2, 3, 4, 5];
  let i: int = 0;
  while i < 5 {
    stdlib::printf("arr[%d] = %d\n", i, arr[i]);
    i = i + 1;
  }
  let i = 0;
  loop {
    if i >= 5 { break; }
    stdlib::printf("arr[%d] = %d\n", i, arr[i]);
    i += 1;
  }
  for let i = 0; i < 5; i += 1 {
    if i % 2 == 0 { continue; }
    stdlib::printf("arr[%d] = %d\n", i, arr[i]);
  }
}

fn main(): int {
  builtin_types();

  let score = 85;
  if score >= 90 {
    stdlib::printf("A\n");
  } else if score >= 75 {
    stdlib::printf("B\n");
  } else {
    stdlib::printf("C\n");
  }

  let result = add(3, 4);
  stdlib::printf("3 + 4 = %d\n", result);

  loops();

  // Variable redeclaration and shadowing
  let i = 10;
  {
    let i = 'i';
    stdlib::printf("shadowed: %c", i); // c
  }
  stdlib::printf("shadowed: %d", i);   // 10

  return 0;
}

fn objects() {
  let v = Vec2 {x: 2, y: 10};
  print_vec(v);
  set_vec(&v);
  print_vec(v);
}

fn set_vec(v: *Vec2, value: int) {
  v.x = value;
  v.y = value;
}

fn print_vec(v: Vec2) {
  stdlib::printf("vec2(%d, %d)", v.x, v.y);
}

struct Vec2 {
  x: int,
  y: int,
}

union Vec2Union {
	i: int[2],
	v: Vec2,
}
```
