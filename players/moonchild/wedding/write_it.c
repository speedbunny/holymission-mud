/* Matt 7-22-94: Made this file so the wedding log can be appended to */
void write_it(string str) {
  write_file("/players/moonchild/wedding/WEDDINGS", str);
}

