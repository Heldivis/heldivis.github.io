#ifndef _FASTIO_H_
#define _FASTIO_H_
#include <bits/stdc++.h>
struct FASTIO {
  int after_point = 6, array_len = 1, array_start = 1;
  char array_delimiter = ' ', array_end = '\n'; 
  FASTIO set_after_point(int x) {
    after_point = x;
    return *this;
  } 
  FASTIO set_array_len(int x) {
    array_len = x;
    return *this;
  } 
  FASTIO set_array_start(int x) {
    array_start = x;
    return *this;
  } 
  FASTIO set_array_delimiter(char x) {
    array_delimiter = x;
    return *this;
  } 
  FASTIO set_array_end(char x) {
    array_end = x;
    return *this;
  } 
  FASTIO operator >> (short &x) {
    int res = 0;
    bool flag = 1;
    char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar())
      if (ch == '-')
        flag = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
      res = (res << 1) + (res << 3) + ch - 48;
    x = flag ? res : ~ res + 1;
    return *this;
  }
  FASTIO operator << (short x) {
    if (x < 0) {
      putchar('-');
      x = ~x + 1;
    }
    int sta[6], top = 0;
    do {
      sta[top++] = x % 10;
      x /= 10;
    } while (x);
    while (top)
      putchar(sta[--top] | 48);
    return *this;
  } 
  FASTIO operator >> (unsigned short &x) {
    int res = 0;
    char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar())
      res = (res << 1) + (res << 3) + ch - 48;
    x = res;
    return *this;
  }
  FASTIO operator << (unsigned short x) {
    int sta[5], top = 0;
    do {
      sta[top++] = x % 10;
      x /= 10;
    } while (x);
    while (top)
      putchar(sta[--top] | 48);
    return *this;
  } 
  FASTIO operator >> (int &x) {
    int res = 0;
    bool flag = 1;
    char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar())
      if (ch == '-')
        flag = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
      res = (res << 1) + (res << 3) + ch - 48;
    x = flag ? res : ~ res + 1;
    return *this;
  }
  FASTIO operator << (int x) {
    if (x < 0) {
      putchar('-');
      x = ~x + 1;
    }
    int sta[10], top = 0;
    do {
      sta[top++] = x % 10;
      x /= 10;
    } while (x);
    while (top)
      putchar(sta[--top] | 48);
    return *this;
  } 
  FASTIO operator >> (unsigned int &x) {
    int res = 0;
    char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar())
      res = (res << 1) + (res << 3) + ch - 48;
    x = res;
    return *this;
  }
  FASTIO operator << (unsigned int x) {
    int sta[10], top = 0;
    do {
      sta[top++] = x % 10;
      x /= 10;
    } while (x);
    while (top)
      putchar(sta[--top] | 48);
    return *this;
  } 
  FASTIO operator >> (long long &x) {
    long long res = 0;
    bool flag = 1;
    char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar())
      if (ch == '-')
        flag = 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
      res = (res << 1) + (res << 3) + ch - 48;
    x = flag ? res : ~ res + 1;
    return *this;
  }
  FASTIO operator << (long long x) {
    if (x < 0) {
      putchar('-');
      x = ~x + 1;
    }
    int sta[20], top = 0;
    do {
      sta[top++] = x % 10;
      x /= 10;
    } while (x);
    while (top)
      putchar(sta[--top] | 48);
    return *this;
  } 
  FASTIO operator >> (unsigned long long &x) {
    unsigned long long res = 0;
    char ch = getchar();
    for (; ch > '9' || ch < '0'; ch = getchar());
    for (; ch >= '0' && ch <= '9'; ch = getchar())
      res = (res << 1) + (res << 3) + ch - 48;
    x = res;
    return *this;
  }
  FASTIO operator << (unsigned long long x) {
    int sta[20], top = 0;
    do {
      sta[top++] = x % 10;
      x /= 10;
    } while (x);
    while (top)
      putchar(sta[--top] | 48);
    return *this;
  } 
  FASTIO operator >> (short x[]) {
    for (int i = 0; i < array_len; i++)
      *this >> x[i + array_start];
    return *this;
  }
  FASTIO operator << (short x[]) {
    for (int i = 0; i < array_len - 1; i++)
      *this << x[i + array_start] << array_delimiter;
    *this << x[array_len - 1 + array_start];
    putchar(array_end);
    return *this;
  } 
  FASTIO operator >> (unsigned short x[]) {
    for (int i = 0; i < array_len; i++)
      *this >> x[i + array_start];
    return *this;
  }
  FASTIO operator << (unsigned short x[]) {
    for (int i = 0; i < array_len - 1; i++)
      *this << x[i + array_start] << array_delimiter;
    *this << x[array_len - 1 + array_start];
    putchar(array_end);
    return *this;
  } 
  FASTIO operator >> (int x[]) {
    for (int i = 0; i < array_len; i++)
      *this >> x[i + array_start];
    return *this;
  }
  FASTIO operator << (int x[]) {
    for (int i = 0; i < array_len - 1; i++)
      *this << x[i + array_start] << array_delimiter;
    *this << x[array_len - 1 + array_start];
    putchar(array_end);
    return *this;
  } 
  FASTIO operator >> (unsigned int x[]) {
    for (int i = 0; i < array_len; i++)
      *this >> x[i + array_start];
    return *this;
  }
  FASTIO operator << (unsigned int x[]) {
    for (int i = 0; i < array_len - 1; i++)
      *this << x[i + array_start] << array_delimiter;
    *this << x[array_len - 1 + array_start];
    putchar(array_end);
    return *this;
  } 
  FASTIO operator >> (long long x[]) {
    for (int i = 0; i < array_len; i++)
      *this >> x[i + array_start];
    return *this;
  }
  FASTIO operator << (long long x[]) {
    for (int i = 0; i < array_len - 1; i++)
      *this << x[i + array_start] << array_delimiter;
    *this << x[array_len - 1 + array_start];
    putchar(array_end);
    return *this;
  } 
  FASTIO operator >> (unsigned long long x[]) {
    for (int i = 0; i < array_len; i++)
      *this >> x[i + array_start];
    return *this;
  }
  FASTIO operator << (unsigned long long x[]) {
    for (int i = 0; i < array_len - 1; i++)
      *this << x[i + array_start] << array_delimiter;
    *this << x[array_len - 1 + array_start];
    putchar(array_end);
    return *this;
  } 
  FASTIO operator >> (float x) {
    float n = 0, t = 0;
    int s = 1, f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())  {
      if (c=='-') f = -1;
      if (c=='.') goto readt;
    }
    for (; isdigit(c) && c != '.'; c = getchar())
      n = n * 10 + (c ^ 48);
    readt : for (; c == '.'; c = getchar());
    for (; isdigit(c); c=getchar()) {
      t = t * 10 + (c ^ 48);
      s = (s << 1) + (s << 3);
    }
    x = f * (n + t / s);
    if (!f)
      return *this;
  }
  FASTIO operator << (float x) {
    switch (after_point) {case 0: printf("%.0f", x);break;
      case 1: printf("%.1f", x);break;
      case 2: printf("%.2f", x);break;
      case 3: printf("%.3f", x);break;
      case 4: printf("%.4f", x);break;
      case 5: printf("%.5f", x);break;
      case 6: printf("%.6f", x);break;
      case 7: printf("%.7f", x);break;
      case 8: printf("%.8f", x);break;
      case 9: printf("%.9f", x);break;
      case 10: printf("%.10f", x);break;
      case 11: printf("%.11f", x);break;
      case 12: printf("%.12f", x);break;
      case 13: printf("%.13f", x);break;
      case 14: printf("%.14f", x);break;
      case 15: printf("%.15f", x);break;
      case 16: printf("%.16f", x);break;
      case 17: printf("%.17f", x);break;
      case 18: printf("%.18f", x);break;
      case 19: printf("%.19f", x);break;
      case 20: printf("%.20f", x);break;
      case 21: printf("%.21f", x);break;
      case 22: printf("%.22f", x);break;
      case 23: printf("%.23f", x);break;
      case 24: printf("%.24f", x);break;
      case 25: printf("%.25f", x);break;
      case 26: printf("%.26f", x);break;
      case 27: printf("%.27f", x);break;
      case 28: printf("%.28f", x);break;
      case 29: printf("%.29f", x);break;
      case 30: printf("%.30f", x);break;
      case 31: printf("%.31f", x);break;
    }
    return *this;
  } 
  FASTIO operator >> (double x) {
    double n = 0, t = 0;
    int s = 1, f = 1;
    char c = getchar();
    for (; !isdigit(c); c = getchar())  {
      if (c=='-') f = -1;
      if (c=='.') goto readt;
    }
    for (; isdigit(c) && c != '.'; c = getchar())
      n = n * 10 + (c ^ 48);
    readt : for (; c == '.'; c = getchar());
    for (; isdigit(c); c=getchar()) {
      t = t * 10 + (c ^ 48);
      s = (s << 1) + (s << 3);
    }
    x = f * (n + t / s);
    if (!f)
      return *this;
  }
  FASTIO operator << (double x) {
    switch (after_point) {
      case 0: printf("%.0lf", x);break;
      case 1: printf("%.1lf", x);break;
      case 2: printf("%.2lf", x);break;
      case 3: printf("%.3lf", x);break;
      case 4: printf("%.4lf", x);break;
      case 5: printf("%.5lf", x);break;
      case 6: printf("%.6lf", x);break;
      case 7: printf("%.7lf", x);break;
      case 8: printf("%.8lf", x);break;
      case 9: printf("%.9lf", x);break;
      case 10: printf("%.10lf", x);break;
      case 11: printf("%.11lf", x);break;
      case 12: printf("%.12lf", x);break;
      case 13: printf("%.13lf", x);break;
      case 14: printf("%.14lf", x);break;
      case 15: printf("%.15lf", x);break;
      case 16: printf("%.16lf", x);break;
      case 17: printf("%.17lf", x);break;
      case 18: printf("%.18lf", x);break;
      case 19: printf("%.19lf", x);break;
      case 20: printf("%.20lf", x);break;
      case 21: printf("%.21lf", x);break;
      case 22: printf("%.22lf", x);break;
      case 23: printf("%.23lf", x);break;
      case 24: printf("%.24lf", x);break;
      case 25: printf("%.25lf", x);break;
      case 26: printf("%.26lf", x);break;
      case 27: printf("%.27lf", x);break;
      case 28: printf("%.28lf", x);break;
      case 29: printf("%.29lf", x);break;
      case 30: printf("%.30lf", x);break;
      case 31: printf("%.31lf", x);break;
      case 32: printf("%.32lf", x);break;
      case 33: printf("%.33lf", x);break;
      case 34: printf("%.34lf", x);break;
      case 35: printf("%.35lf", x);break;
      case 36: printf("%.36lf", x);break;
      case 37: printf("%.37lf", x);break;
      case 38: printf("%.38lf", x);break;
      case 39: printf("%.39lf", x);break;
      case 40: printf("%.40lf", x);break;
      case 41: printf("%.41lf", x);break;
      case 42: printf("%.42lf", x);break;
      case 43: printf("%.43lf", x);break;
      case 44: printf("%.44lf", x);break;
      case 45: printf("%.45lf", x);break;
      case 46: printf("%.46lf", x);break;
      case 47: printf("%.47lf", x);break;
      case 48: printf("%.48lf", x);break;
      case 49: printf("%.49lf", x);break;
      case 50: printf("%.50lf", x);break;
      case 51: printf("%.51lf", x);break;
      case 52: printf("%.52lf", x);break;
      case 53: printf("%.53lf", x);break;
      case 54: printf("%.54lf", x);break;
      case 55: printf("%.55lf", x);break;
      case 56: printf("%.56lf", x);break;
      case 57: printf("%.57lf", x);break;
      case 58: printf("%.58lf", x);break;
      case 59: printf("%.59lf", x);break;
      case 60: printf("%.60lf", x);break;
      case 61: printf("%.61lf", x);break;
      case 62: printf("%.62lf", x);break;
      case 63: printf("%.63lf", x);break;
    }
    return *this;
  } 
  FASTIO operator >> (float x[]) {
    for (int i = 0; i < array_len; i++)
      *this >> x[i + array_start];
    return *this;
  }
  FASTIO operator << (float x[]) {
    for (int i = 0; i < array_len - 1; i++)
      *this << x[i + array_start] << array_delimiter;
    *this << x[array_len - 1 + array_start];
    putchar(array_end);
    return *this;
  } 
  FASTIO operator >> (double x[]) {
    for (int i = 0; i < array_len; i++)
      *this >> x[i + array_start];
    return *this;
  }
  FASTIO operator << (double x[]) {
    for (int i = 0; i < array_len - 1; i++)
      *this << x[i + array_start] << array_delimiter;
    *this << x[array_len - 1 + array_start];
    putchar(array_end);
    return *this;
  } 
  FASTIO operator >> (char &ch) {
    do {
      ch = getchar();
    } while (ch == ' ' || ch == '\n');
    return *this;
  }
  FASTIO operator << (char ch) {
    putchar(ch);
    return *this;
  } 
  FASTIO operator >> (char str[]) {
    char ch;
    for (int i = 0;; i++) {
      ch = getchar();
      if (ch == ' ' || ch == '\n')
        return *this;
      str[i] = ch;
    }
    return *this;
  }
  FASTIO operator << (char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len; i++)
      putchar(str[i]);
    return *this;
  } 
  FASTIO operator >> (std::string &str) {
    str = "";
    char ch;
    for (int i = 0;; i++) {
      ch = getchar();
      if (ch == ' ' || ch == '\n')
        return *this;
      str += ch;
    }
    return *this;
  }
  FASTIO operator << (std::string str) {
    for (int i = 0; i < int(str.size()); i++)
      putchar(str[i]);
    return *this;
  } 
}fio;
#endif  //  _FASTIO_H_
