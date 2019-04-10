# SoalShift_modul3_A06

1. Buatlah program C yang bisa menghitung faktorial secara parallel lalu menampilkan hasilnya secara berurutan
Contoh:
    ./faktorial 5 3 4
    3! = 6
    4! = 24
    5! = 120


```
Langkah-Langkah :
Soal ini membutuhkan thread sejumlah inputan, maka gunakan argumen argc untuk menghitung berapa inputan dan argv[] untuk menyimpan inputan, lalu lakukan loop sebanyak argc-1 untuk membuat thread masing masing perhitungan faktorial angka.
```

2. Pada suatu hari ada orang yang ingin berjualan 1 jenis barang secara private, dia memintamu membuat program C dengan spesifikasi sebagai berikut:
	a) Terdapat 2 server: server penjual dan server pembeli
	b) 1 server hanya bisa terkoneksi dengan 1 client
	c) Server penjual dan server pembeli memiliki stok barang yang selalu sama
	d) Client yang terkoneksi ke server penjual hanya bisa menambah stok
		i) Cara menambah stok: client yang terkoneksi ke server penjual mengirim string “tambah” ke server lalu stok bertambah 1
	e) Client yang terkoneksi ke server pembeli hanya bisa mengurangi stok
		i) Cara mengurangi stok: client yang terkoneksi ke server pembeli mengirim string “beli” ke server lalu stok berkurang 1
	f) Server pembeli akan mengirimkan info ke client yang terhubung dengannya apakah transaksi berhasil atau tidak berdasarkan ketersediaan stok
		i) Jika stok habis maka client yang terkoneksi ke server pembeli akan mencetak “transaksi gagal”
		ii)Jika stok masih ada maka client yang terkoneksi ke server pembeli akan mencetak “transaksi berhasil”
	g) Server penjual akan mencetak stok saat ini setiap 5 detik sekali
	h) Menggunakan thread, socket, shared memory

```
Langkah-Langkah :
disini karena kami masih kesulitan, maka kami hanya membuat server penjual dan client untuk pembeli. karena menggunakan shared memory maka buat 2 file program pembeli dan penjual, di program pembeli terdapat 2 thread fungsi beli dan lihat stok, sedangkan di program penjual terdapat 2 thread fungsi tambah stok, dan lihat stok. Kedua program ini menunjuk ke satu alamat memori yang sama, alamat memori ini berisi jumlah stok barang, sehingga jika salah satu berjalan, maka perubahan stok juga akan terjadi di program yang lain.
```



4. Buatlah sebuah program C dimana dapat menyimpan list proses yang sedang berjalan (ps -aux) maksimal 10 list proses. Dimana awalnya list proses disimpan dalam di 2 file ekstensi .txt yaitu  SimpanProses1.txt di direktori /home/Document/FolderProses1 dan SimpanProses2.txt di direktori /home/Document/FolderProses2 , setelah itu masing2 file di  kompres zip dengan format nama file KompresProses1.zip dan KompresProses2.zip dan file SimpanProses1.txt dan SimpanProses2.txt akan otomatis terhapus, setelah itu program akan menunggu selama 15 detik lalu program akan mengekstrak kembali file KompresProses1.zip dan KompresProses2.zip 
Dengan Syarat : 
	a) Setiap list proses yang di simpan dalam masing-masing file .txt harus berjalan bersama-sama
	b) Ketika mengkompres masing-masing file .txt harus berjalan bersama-sama
	c) Ketika Mengekstrak file .zip juga harus secara bersama-sama
	d) Ketika Telah Selesai melakukan kompress file .zip masing-masing file, maka program akan memberi pesan “Menunggu 15 detik untuk mengekstrak kembali”
	e) Wajib Menggunakan Multithreading
	f) Boleh menggunakan system


```
Langkah-Langkah :
1. pertama-tama buat 4 thread.
2. thread ke 1 berisi 2 command ps aug dan disimpan. ke 2 file bernama SimpanProses1.txt, dan SimpanProses2.txt.
3. bikin variabel status ps menjadi 1.
4. thread ke 2 berisi 2 command zip untuk mengcompres file bernama SimpanProses1.txt, dan SimpanProses2.txt.
5. buatlah 1 zip menjadi 1.
6. thread ke 3 berisi 2 command unzip untuk mengcompres file bernama KompresProses1.zip , dan KompresProses2.zip.
7. mwmbuat keempat thread tersebut dengan fungsi pthread_create dengan catatan di thread 3 menyisipkan fungsi printf serta sleep.
```

