/*** LAZYAKTION.H ***/

#ifndef __LazyAktion_h
#define __LazyAktion_h

#include <list>
using namespace std;

// Oberklasse LazyAktion
template <class T>
class LazyAktion
{
   public:
      LazyAktion( list<T>* ptLazyListe )
                   : p_ptLazyListe( ptLazyListe ) {}
      virtual ~LazyAktion() {}
      virtual void vAusfuehren() = 0;
   protected:
      list<T>*	p_ptLazyListe;	// Zeiger auf p_ListeObjekte
};


// LazyPushFront
template <class T>
class LazyPushFront : public LazyAktion<T>
{
   public:
      LazyPushFront(const T& einObjekt, list<T>* eineListe)
                      : LazyAktion<T>(eineListe)
                      , p_tObjekt(einObjekt) {}
      virtual ~LazyPushFront() {}
      void vAusfuehren() { p_ptLazyListe->push_front(p_tObjekt); }
   private:
      T	p_tObjekt;
};


// LazyPushBack
template <class T>
class LazyPushBack : public LazyAktion<T>
{
   public:
      LazyPushBack(const T& einObjekt, list<T>* eineListe)
                      : LazyAktion<T>(eineListe)
                      , p_tObjekt(einObjekt) {}
      virtual ~LazyPushBack() {}
      void vAusfuehren() { p_ptLazyListe->push_back(p_tObjekt); }
   private:
      T	p_tObjekt;
};


// LazyErase
template <class T>
class LazyErase : public LazyAktion<T>
{
   // typedef fuer iterator
   typedef typename list<T>::iterator iterator;
   typedef typename list<T>::const_iterator const_iterator;

   public:
      LazyErase(iterator itObjekt, list<T>* eineListe)
                      : LazyAktion<T>(eineListe)
                      , p_itObjekt(itObjekt) {}
      virtual ~LazyErase() {}
      void vAusfuehren() { p_ptLazyListe->erase(p_itObjekt); }
   private:
      iterator	p_itObjekt;	// bei erase Iterator speichern
};


#endif