# Görüntü İşleme
## Görüntü işlemede kullanılan Ortalama Filtre sayesinde görüntü üzerindeki gürültüyü azaltmak. Yazdığımız seri programı admin makinası üzerinde g++ ile derleyiniz.
Görüntü işleme algoritmaları bir görüntüyü bilgisayar yardımıyla işleyebilmek amacıyla ilk etapda görüntüyü iki veya daha fazla boyuta sahip matrise dönüştürür. Bu matrisin her bir elemanının değeri ilgili görüntünün her bir pikselinin sayısal değerine eşittir.

**Ortalama Filtre** belirli bir pencere aralığında (projede pencere boyutu 5x5 olarak kullanılıyor) sayıların ortlamasını bulmayı ve bu sayede söz konusu sayılar arasındaki aşırı farklılıkları ortadan kaldırmayı hedeflenmektedir. Yani Ortalama filtre sayesinde komşularından belirgin bir şekilde ayrışan piksellerin tespit edilmesi ve yumuşatılması amaçlanmaktadır.

Projede değerlendirmeniz amacıyla **görüntü dosyası(Goruntu3.jpg)** ve bu dosyanın **matris temsilleri (GoruntuMatrisi3.txt)** içeren düz yazı dosya paylaşılmıştır. Matris dosyasının ilk satırında ilgili matrisin kaç satırdan ve kaç sütundan oluştuğu bilgisi yer almaktadır. Görüntüye tuz ve biber gürültüsü **(salt&pepper noise)** eklenmiştir. Ortalama filtre sayesinde bu gürültünün görüntüler üzerinden kaldırılması hedeflenmektedir. Bu doğrultuda matris dosyasından ortalama filtre uygulayarak yeni bir matris oluşturulması ve bu matris görüntüyü dönüştürerek paylaşılan orjinal görüntüyle karşılaştırlması  yapılır.

Ortalama filtre bir görüntüdeki her bir piksel için, pencere boyutundaki komşu piksellerin ortalama değerini elde eder ve ilgili piksele bu ortalama değeri atar. Bu işlem her piksel için sıra ile uygulanır. 5x5'lik komşuluk beklenirken, filtre uygulanan piksel (ilgili pencerenin 3.satırında ve 3. sütununda yer alan piksel) bu matirisin ortasına getirilerek komşuları belirlenir.

- 5x5'lik ortalama filtrede ilgili pikselin 2'şer komşuluklarına bakılır. Örneğin **(x,y)** pozisyonundaki bir pikselin komşuları aşağıdaki gibidir.

![Adsiz](https://user-images.githubusercontent.com/66306220/86360991-da701800-bc7b-11ea-90c1-a99628520c83.jpg)

- 5x5’lik ortalama filtrede matrisin *ilk 2 satırındaki* ve *ilk 2 sütunundaki*, ayrıca *son 2 satırındaki* ve *2 sütunundaki piksellerine* filtre ~~uygulanmaz.~~ Örneğin 5x5’lik ortalama filtre için, GoruntuMatrisi3.txt isimli dosya içerisindeki filtre uygalanacak ilk değer 114’dür.

![Uygalacak_ilk_filtre](https://user-images.githubusercontent.com/66306220/86361999-5159e080-bc7d-11ea-888e-689484bd3951.png)

## Değeri 114 olan piksel için filtrelenin nasıl olacağı aşağıda açıklanmıştır.

**1.**	114’ ün 5x5’lik komşu değerleri tespit edilir. (kırmızı dikdörtgenin içerisinde kalan kısım)

**77-113-195-77-76-82-82-77-87-21-105-106-114-105-101-5-128-122-122-122-72-82-82-44-71**

**2.**	Bu değerler toplanır: **2268**

**3.**  Ortalama hesaplanır: **2268 / 25 = 90**

Filtre uygalancak pikselin eski değeri **114**, yeni değeri **90**’dır. Dolayısıyla sonuç matrisinde **114**’ün bulunduğu konuma **90** değeri kaydedilecektir. (Ana matris üzerinde değişiklik yapılmıyor.)

## Proje Çalıştırma
Program komut satırından tek bir argüman alarak çalıştırılmalıdır. Bu argüman işleyeceğiniz görüntüye ait düz yazı matris dosyasının yoluyla birlikte adıdır.

***Örnek: ./proje1.x     /opt/goruntuDosyalari/GoruntuMatrisi1.txt***
İki boyutlu yeni bir dinamik dizi oluşturuldu ve ilk diziye ortalama filtre uygulanması sonrasında elde edilen piksel değerleri bu dizide depolandı.(Bu dizinin boyutu giriş dosyasındaki matrisi saklayan dizinin boyutu ile aynıdır. Dinamik dizi de program sona ermeden yok edilmiştir.)

Filtreleme işlemi tamamlandıktan sonra, filtrelenmiş değerleri içeren sonuç matrisi bir düz yazı dosya içerisine kaydedildi. (Giriş dosyasının adı **GoruntuMatrisi3.txt** ise çıkış dosyasının adı **GoruntuMatrisi3_filtered.txt** oldu)

Filtreleme işlemi tamamlandıktan sonra, filtrelenmiş değerleri içeren sonuç matrisi (çıkış dosyası) bir görüntü dosyasına dönüştürülmüştür. (Proje klasörü içerisinde bulunan script’ten (**Proje1Script.sh**) faydalanabilirsiniz. Örneğin **GoruntuMatrisi3.txt** isimli dosyayı işlenir ve filtrelenmiş sonuç matrisini **GoruntuMatrisi3_filtered.txt** isimli dosyanın içine kaydedilir. Söz konusu script’e çalıştırma yetkisi vermek için aşağıdaki komutu sadece bir kereliğine çalıştırınız.)

***$ chmod u+x Proje1Script.sh***

Daha sonra söz konusu script’i aşağıdaki gibi kullanabilirsiniz:

***$ ./Proje1Script.sh  GoruntuMatrisi3_filtered.txt***

Yukarıdaki komut görüntüyü dönüştürür, filtrelenmiş matris dosyasını kendisine argüman olarak alır ve sonrasında **GoruntuMatrisi3_filtered.jpg** isimli bir görüntü dosyası oluşturur. Bu filtrelenmiş görüntüyü gürültü içeren orijinal görüntü ile karşılaştırınız. C++ programının doğru çalışıp çalışmadığını anlayabilirsiniz.

### İlk hali: Goruntu3.jpg

![Goruntu3](https://user-images.githubusercontent.com/66306220/86370508-83247480-bc88-11ea-9001-18b27633f8a7.jpg)

### Filtre uygulanmış hali: GoruntuMatrisi3_filtered.jpg

![GoruntuMatrisi3_filtered](https://user-images.githubusercontent.com/66306220/86370482-7b64d000-bc88-11ea-9112-82c9b6219718.jpg)

