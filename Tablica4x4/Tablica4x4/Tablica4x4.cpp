﻿// PrzykladMenu.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

// tablica4x4_v01_C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Under "Project -> Properties -> C/C++ -> Preprocessor -> Preprocessor Definitions" add _CRT_SECURE_NO_WARNINGS

//#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#define L_WIERSZY 4
#define L_KOLUMN  4

void wprowadz_dane(int tab[][L_KOLUMN])
{
  for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
  {
    for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
    {
      printf_s("Podaj liczbe [%d][%d]:\n", wiersze, kolumny);
      int liczba;
      scanf_s("%d", &liczba); // http://strefakodera.pl/programowanie/c/wczytywanie-i-wypisywanie-danych-w-c-za-pomoca-scanf-i-printf-szybsza-alternatywa-dla-cout-oraz-cin
      tab[wiersze][kolumny] = liczba;
    }
  }
}

void wprowadz_dane_losowo(int tab[][L_KOLUMN])
{
  for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
  {
    for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
    {
      tab[wiersze][kolumny] = std::rand() % 100 + 0;
    }
  }
}

void wyswietl_dane(int tab[][L_KOLUMN])
{
  int temp = 0;
  for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
  {
    for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
    {
      printf_s("%4d", tab[wiersze][kolumny]);
    }
    printf_s("\n");
  }
  printf_s("\n");
}

void wyswietl_dane_posortowane(int tab[])
{
  printf_s("Posortowana tablica: \n");
  for (int i = 0; i < L_WIERSZY * L_KOLUMN; i++)
  {
    printf_s("%d ", tab[i]);
  }
  printf_s("\n");
}

float srednia(int tab[][L_KOLUMN])
{
  int calosc = 0;
  for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
  {
    for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
    {
      calosc = calosc + tab[wiersze][kolumny];
    }
  }
  int ilosc_pol = L_KOLUMN * L_WIERSZY;
  float srednia = calosc / ilosc_pol;

  return srednia;
}

float mediana(int tab[][L_KOLUMN])
{
  int tab_sort_temp[L_WIERSZY * L_KOLUMN] = { 0 };
  int pole = 0;
  for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
  {
    for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
    {
      tab_sort_temp[pole] = tab[wiersze][kolumny];
      pole++;
    }
  }

  int ilosc_pol = L_KOLUMN * L_WIERSZY;
  std::sort(tab_sort_temp, tab_sort_temp + ilosc_pol);

  wyswietl_dane_posortowane(tab_sort_temp);

  float mediana = 0;
  if (ilosc_pol % 2 == 0)
  {
    int x = tab_sort_temp[(ilosc_pol - 1) / 2] + tab_sort_temp[ilosc_pol / 2];
    mediana = x / 2;
  }
  else
  {
    mediana = (float)(tab_sort_temp[ilosc_pol / 2]);
  }

  return mediana;
}

//http://cpp0x.pl/kursy/Kurs-C++/Obsluga-plikow/305
void zapisz_dane(int tab[][L_KOLUMN])
{
  std::fstream plik;
  //http://www.cplusplus.com/reference/fstream/fstream/open/
  plik.open("tablica.txt", std::ios::out | std::ios::trunc);
  if (plik.good() == true)
  {
    for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
    {
      for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
      {
        plik << tab[wiersze][kolumny] << " ";
      }
    }

    plik.close();
  }
}

// https://www.p-programowanie.pl/matura-z-informatyki/odczyt-danych-z-pliku-c/ + komentarze.
void wczytaj_dane(int tab[][L_KOLUMN])
{
  std::fstream plik;
  plik.open("tablica.txt", std::ios::in);
  if (plik.good() == true)
  {
    for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
    {
      for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
      {
        plik >> tab[wiersze][kolumny];
      }
    }

    plik.close();
  }
}

void zamien_min_max(int tab[][L_KOLUMN])
{
  int min = tab[0][0], max = tab[0][0];
  for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
  {
    for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
    {
      if (tab[wiersze][kolumny] < min)
      {
        min = tab[wiersze][kolumny];
      }

      if (tab[wiersze][kolumny] > max)
      {
        max = tab[wiersze][kolumny];
      }
    }
  }

  for (int wiersze = 0; wiersze < L_WIERSZY; wiersze++)
  {
    for (int kolumny = 0; kolumny < L_KOLUMN; kolumny++)
    {
      int wartosc = tab[wiersze][kolumny];
      if (wartosc == min)
      {
        tab[wiersze][kolumny] = max;
      }
      if (wartosc == max)
      {
        tab[wiersze][kolumny] = min;
      }
    }
  }
}

void menu(void)
{
  printf_s("\n");
  printf_s("1 - wprowadz dane\n");
  printf_s("2 - wyswietl dane\n");
  printf_s("3 - oblicz srednia i mediane\n");
  printf_s("4 - zamien wartosc minimalna z maksymalna\n");
  printf_s("5 - generuj dane losowo\n");
  printf_s("z - zapisz dane do pliku\n");
  printf_s("w - wczytaj dane z pliku\n");
  printf_s("k - koniec programu\n");
  printf_s("\n");
}

int main()
{
  int tablica[L_WIERSZY][L_KOLUMN] = { 0 };
  char opcja = 0;
  srand(time(NULL)); //konfiguracja losowania liczb: http://cpp0x.pl/kursy/Kurs-C++/Poziom-2/Pseudolosowe-liczby-calkowite/290

  while (opcja != 'k')
  {
    menu();
    opcja = _getch();

    switch (opcja)
    {
    case '1':
      wprowadz_dane(tablica);
      break;

    case '2':
      wyswietl_dane(tablica);
      break;

    case '3':

      printf_s("Srednia wartosci znajdujacych sie w tabeli wynosi: %f\n", srednia(tablica));
      printf_s("Mediana wartosci znajdujacych sie w tabeli wynosi: %f\n", mediana(tablica));
      break;

    case '4':
      zamien_min_max(tablica);
      printf_s("Zamieniono wartosc minimalna z maksymalna.\n");
      break;

    case '5':
      wprowadz_dane_losowo(tablica);
      printf_s("Wygenerowano dane losowo.\n");
      break;

    case 'z':
      zapisz_dane(tablica);
      printf_s("Zapisano dane do pliku.\n");
      break;

    case 'w':
      wczytaj_dane(tablica);
      printf_s("Odczytano dane z pliku.\n");
      break;

    case 'k':
      //zakonczenie programu
      break;

    default:
      printf_s("Wybierz wlasciwa opcje.\n\n");
      break;
    }
  }

  return 0;
}
