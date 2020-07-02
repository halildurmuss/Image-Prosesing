# Görüntü İşleme
## Görüntü işlemede kullanılan Ortalama Filtre sayesinde görüntü üzerindeki gürültüyü azaltmak.
Görüntü işleme algoritmaları bir görüntüyü bilgisayar yardımıyla işleyebilmek amacıyla ilk etapda görüntüyü iki veya daha fazla boyuta sahip matrise dönüştürür. Bu matrisin her bir elemanının değeri ilgili görüntünün her bir pikselinin sayısal değerine eşittir.

Ortalama Filtre belirli bir pencere aralığında (projede pencere boyutu 5x5 olarak kullanılıyor) sayıların ortlamasını bulmayı ve bu sayede söz konusu sayılar arasındaki aşırı farklılıkları ortadan kaldırmayı hedeflenmektedir. Yani Ortalama filtre sayesinde komşularından belirgin bir şekilde ayrışan piksellerin tespit edilmesi ve yumuşatılması amaçlanmaktadır.

Projede değerlendirmeniz amacıyla **görüntü dosyası(Goruntu3.jpg)** ve bu dosyanın **matris temsilleri (GoruntuMatrisi3.txt)** içeren düz yazı dosya paylaşılmıştır. Matris dosyasının ilk satırında ilgili matrisin kaç satırdan ve kaç sütundan oluştuğu bilgisi yer almaktadır. Görüntüye tuz ve biber gürültüsü (salt&pepper noise) eklenmiştir. Ortalama filtre sayesinde bu gürültünün görüntüler üzerinden kaldırılması hedeflenmektedir. Bu doğrultuda matris dosyasından ortalama filtre uygulayarak yeni bir matris oluşturulması ve bu matris görüntüyü dönüştürerek paylaşılan orjinal görüntüyle karşılaştırlması  yapılır.

Ortalama filtre bir görüntüdeki her bir piksel için, pencere boyutundaki komşu piksellerin ortalama değerini elde eder ve ilgili piksele bu ortalama değeri atar. Bu işlem her piksel için sıra ile uygulanır. 5x5'lik komşuluk beklenirken, filtre uygulanan piksel (ilgili pencerenin 3.satırında ve 3. sütununda yer alan piksel) bu matirisin ortasına getirilerek komşuları belirlenir.

5x5'lik ortalama filtrede ilgili pikselin 2'şer komşuşuklarına bakılır. Örneğin (x,y) pozisyonundaki bir pikselin komşuları aşağıdaki gibidir.

![Adsiz](https://user-images.githubusercontent.com/66306220/86360991-da701800-bc7b-11ea-90c1-a99628520c83.jpg)
