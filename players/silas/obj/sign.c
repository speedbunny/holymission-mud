id(str) {
        return str == "sign";
        }

short() {
return "wooden sign";
        }

long() {
write("Welcome to F'ghant!\n");
       }

reset(arg) {
  if (arg) return 1;
  return 1;
}

init() {
        add_action("read_sign","read");
}

read_sign(str) {
        if (!id(str)) return 0;
        long();
        return 1;
}
