# 5° lezione algoritmi

Due Date: October 15, 2024
Materia: Algoritmi e Laboratorio
Status: Done

## Ripasso lezione precedente

- Minheap: priorità numeri piccoli
- Maxheap: prioprità numeri grandi

Ogni nodo ha sempre proprietà più al/ta, uguale rispetto ai suoi figli. La maggior parte dell'operazioni impiega $O(log_n)$ poiché è un albero bilanciato, tranne l'ultimo livello in cui i nodi si ammassano su un solo lato.

# HEAP struttura dati efficiente

La sua rappresentazione fisica è un array.

Il livello fisico è un array, mentre il livello astratto è un albero.

Caso diverso per  l’ array dove rappresentazione fisica e astratta corrispondono.

array

|  |  |  |  |
| --- | --- | --- | --- |

Lista (rappresentazione astratta)

![Diagramma senza titolo.drawio.png](5%C2%B0%20lezione%20algoritmi%20120c5c8ba9398026b7cadef0e2dde327/Diagramma_senza_titolo.drawio.png)

a livello fisico gli elementi non sono contigui ma sparsi

## Come vie rappresentato l’ HEAP a livello astratto?

![Diagramma senza titolo.drawio.png](5%C2%B0%20lezione%20algoritmi%20120c5c8ba9398026b7cadef0e2dde327/Diagramma_senza_titolo.drawio%201.png)

## Come viene rappresenato a livello fisico?

**Viene rappresentato a livello fisico mediante un array**

![Diagramma senza titolo.drawio.png](5%C2%B0%20lezione%20algoritmi%20120c5c8ba9398026b7cadef0e2dde327/Diagramma_senza_titolo.drawio%202.png)

![Diagramma senza titolo.drawio.png](5%C2%B0%20lezione%20algoritmi%20120c5c8ba9398026b7cadef0e2dde327/Diagramma_senza_titolo.drawio%203.png)

Ordinandolo in questa maniera, si perdermo le informazioni che si aveva nel albero modo possibile per mantenerle sarebbe allocare un altro vettore dove si vanno a memorizzare l'informazione, dove si trova il figlio sinistro. Il figlio destro segue il figlio sinistro, quindi per ottenere il figlio destro devo andare a $i+1$. I figli dello stesso padre sono continui.

## Trovare i figli con unico vettore

### **Con i puntatori**

```
**LEFT(X)
	return x->getLeft()
RIGHT(X)
	return x->getRight()**	
```

### **Con gli indici**

```
**LEFT(i)
	retun 2*i
RIGHT(i)
	return 2*i+1**
```

In questo modo, la lavorazione è veloce e gli elementi della rete sono continui. Conviene per questa operazioni fa iniziare l'indice da uno anziché da zero.

### Trovare il parent

```
**PARENT(i)
	return floor(i/2) ⌊i/2⌋**
```

## Trovare i figli con la moltiplicazione BIT a BIT

```
**LEFT(i)
	return (i << 1)

RIGHT(i)
	return	(i << 1 | 1)
	
PARENT(i)
	return (i >> 1)**	
```

L’ HEAP È quello che conosciamo delle astratto. Fisicamente, l’HEAP è un vettore  in è possibile ricostruire la struttura astratta, grazie agli indici (con elementi ordinati da sinistra e a destra)

A questo punto possiamo dare una nuova definizione di HEAP

> **Un heap è un albero binario posizionale completo a meno dell’ultimo livello, a patto che tutti i suoi elementi sono allineati a sinistra. Fisicamente un HEAP è un vettore in cui tutti i nodi sono disposti in ordine da sinistra verso destra. Da questo vettore è possibile costruire una struttura ad albero grazie agli indici degli elementi all'interno del vettore.**
> 

## Differenza tra struttura fisica ed astratta di un HEAP

La struttura astratta non lineare è quella di un albero, ma quella fisica è di un array.

## Come costruire un HEAP?

S = < 7,9,3,5,4,11,17,13,2,6>

Partendo da un HEAP vuoto si vogliono inserire gli elementi di S. 

![Diagramma senza titolo.drawio.png](5%C2%B0%20lezione%20algoritmi%20120c5c8ba9398026b7cadef0e2dde327/Diagramma_senza_titolo.drawio%204.png)

Come abbiamo detto prima l’heap si può rappresentare anche mediante un array che coincide con la rappresentazione fisica cioè in memoria.

![Diagramma senza titolo.drawio.png](5%C2%B0%20lezione%20algoritmi%20120c5c8ba9398026b7cadef0e2dde327/Diagramma_senza_titolo.drawio%205.png)

 Sicuramente non si ha un HEAP ci saranno sicuramente dei sotto-alberi che lo sono.

 Le foglie sono sicuramente HEAP. Le foglie sono la metà dei nodi.

La procedura `heapfy()` si chiama sui nodi che non sono foglie. Cioè partendo dal livello prima delle foglie.

Inizio a percorrere foglie da sinistra verso destra trovando il modo in cui applicare la provedura `heapfy()` . $\frac{n}{2}$ è Primo elemento, a non esere una foglia nel vettore.

```
**BULD_MIN_HEAP(A,N)
	FOR i <- floor(n/2)  DOWN TO 1 DO
		HEAPFY(A,i)**
```

Questa procedura ha complessità $O(n)$.

![Screenshot 2024-10-16 alle 14.33.43.png](5%C2%B0%20lezione%20algoritmi%20120c5c8ba9398026b7cadef0e2dde327/Screenshot_2024-10-16_alle_14.33.43.png)

> **Se si costruisce un heap inserendo ogni singolo elemento $\to O(nlogn)$**
> 

> **Se si costruisce un heap da un array $\to O(n)$**
> 

> Si può notare come la disposizione degli elementi nell’ heap sono disposti diversamente rispetto a quando si inserisce un singolo elemento.
> 

```
HEAPFY(A,i)
	l <- left(i)
	r <- right(i)
	min <- righy(i)
	if(l <= HeapSize  && A[l] < A[min]) then min <- l
	if(r <= HeapSize && A[r] < A[min] then min <- r
	if (min != i) then {swap(A,i,min); Heapfy(A,min);} 
```

nel vettore che si stan considerando si hanno due variabili che indica quanti elementi ci sono nel vettore(`heapSize)`  e la lunghezza effettiva del vettore(`N)`.

## Inserimento

Se con un heap c’era il problema di capire come far andare il numero al suo posto con un array è molto più semplice capirlo perchè se si dovessse inserire un nuovo elemento questo sarà nella posizione `heapSize + 1`

```
INSERT(A,K)
	A[heapSize +1] <- K
	heapSize += 1
	i <- heapSize elemento appena inserito 
	P <- parent(i) padre dell' nuovo elemento
		WHILE( P != 0 && A[P] > A[i]) ciclo per inserie l'elemento mantenento l'ordinamento parziale
		SWAP(A,i,P)
		i <- P
		P <- PARENT(i)
	
	
```

## EXTRACT-MIN

```
EXTRACT-MIN(A)
	SWAP(A,1,heapSize)
	heapSize -= 1
	HEAPFY(A,1)
```

## Algoritmi di ordinamento con l’HEAP

![Diagramma senza titolo.drawio.png](5%C2%B0%20lezione%20algoritmi%20120c5c8ba9398026b7cadef0e2dde327/Diagramma_senza_titolo.drawio%205.png)

 E come il Selection sort ma con complessità $O(nlogn)$

 Si sta usando una struttura dati per creare un algoritmo ordinamento efficienti e con soluzioni banali.

```
HEAPSORT(A,N)
	BULID-MAX-HEAP(A,N) O(n)
	FOR i <- 1 to n - 1 
		EXTRACT-MAX(A)  O(logn)
```

L’HEAP SORT lavora in loco  e implementa l’albero direttamnte dall’ array. Si potrebbe implementare anche in maniera stabile. é migliore del Marge-Sort