int main() {
  float pi = acos(-1.0);

  float angle, x, y;
  sscanf(Stdio.stdin->gets(), "%f", angle);
  sscanf(Stdio.stdin->gets(), "%f %f", x, y);
  angle = angle * pi / 180;

  float rx = x * cos(angle) - y * sin(angle);
  float ry = x * sin(angle) + y * cos(angle);
  write("%f %f\n", rx, ry);

  return 0;
}

