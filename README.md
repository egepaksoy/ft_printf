# 🖨️ ft_printf

`ft_printf`, C dilindeki standart `printf` fonksiyonunun yeniden yazımıdır. `%d`, `%s`, `%x`, `%p` gibi formatları destekler ve terminale biçimlendirilmiş çıktı verir.

## 🛠️ Derleme

```bash
make
````

## 🔧 Desteklenen Formatlar

* `%c` : Karakter
* `%s` : String
* `%d` / `%i` : Integer
* `%u` : Unsigned int
* `%x` / `%X` : Hexadecimal
* `%p` : Pointer adresi
* `%%` : Yüzde işareti

## 🔁 Kullanım

```c
ft_printf("Sayi: %d, Yazi: %s\n", 42, "Merhaba");
```

## 🧠 Öğrenilenler

* Variadic fonksiyonlar (`va_list`)
* Format ayrıştırma ve yönlendirme
* Hex, unsigned, pointer yazdırma
* `write()` üzerinden karakter karakter çıktı verme
