#include <iostream>
#include <string>
#include <vector>
#include <unistd.h> // for sleap
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
#include "enum.h"
class Movie
{
     string m_movie_name{};
     string m_movie_rating{};
     int m_movie_wathed_times{};

public:
     Movie(string movie_name, string movie_rating, int movie_wathed_times)
         : m_movie_name(movie_name),
           m_movie_rating(movie_rating),
           m_movie_wathed_times(movie_wathed_times)
     {
          cout << "\n ## Constructor for: " << m_movie_name << " ## \n"
               << endl;
     }
     void setMovie(string movie_name, string movie_rating, int movie_wathed_times)
     {
          m_movie_name = movie_name;
          m_movie_rating = movie_rating;
          m_movie_wathed_times = movie_wathed_times;
     }
     string getMovieName() const { return m_movie_name; }
     string getMovieRating() const { return m_movie_rating; }
     int getMovieWatchTime() const { return m_movie_wathed_times; }

     void printMovie()
     {
          cout << "# Movie name is: "
               << m_movie_name
               << " movie rating is: "
               << m_movie_rating
               << " and you watch this movie: "
               << m_movie_wathed_times
               << " times! # " << endl;
     }
     void setMovieWatchTime()
     {
          m_movie_wathed_times++;
     }
};

class Movies
{
     vector<Movie> movie_list{};

public:
     void addMovieToList(Movie &mv)
     {
          movie_list.push_back(mv);
     }
     void printAllMovies()
     {
          for (auto &mv : movie_list)
          {
               cout << "\n|Movie added whit this parameters|\n";
               cout << "==============START===============\n";
               cout << "movie name: "
                    << mv.getMovieName()
                    << " rate: "
                    << mv.getMovieRating()
                    << " w. t. "
                    << mv.getMovieWatchTime()
                    << "\n";
               cout << "===============END================\n";
          }
     }
     bool checExistingMovie(string &mv_name)
     {
          for (size_t i = 0; i < movie_list.size(); i++)
          {
               if (movie_list[i].getMovieName() == mv_name)

                    return false;

               else
                    return true;
          }
          return true;
     }
};

int main()
{
     int nr_movies{};
     string local_movie_name{};
     string local_movie_rating{};
     int local_movie_watch_times{};
     Movies my_movies_list{};
     string object_name{};
     bool movie_presece{};
     cout << "================================\n";
     cout << "Welcome to my program!\n";

     cout << "How many movies do you want to add?\n";
     cin >> nr_movies;
     cout << "Nice, you choose to add " << nr_movies << " movies\n";

     for (size_t i = 0; i < nr_movies; i++)
     {
          cout << "Enter new object name: \n";
          cin >> object_name;
          cout << "Enter new movie name: \n";
          cin >> local_movie_name;
          cout << "Enter movie rating from fallowing G, P, PG-13, R: \n";
          cin >> local_movie_rating;
          cout << "Enter movie watched time: \n";
          cin >> local_movie_watch_times;
          movie_presece = my_movies_list.checExistingMovie(local_movie_name);

          if (!movie_presece)
          {
               cout << "Movie alredy is in the list!\n";
          }
          else
          {
               Movie object_name{local_movie_name, local_movie_rating, local_movie_watch_times};
               my_movies_list.addMovieToList(object_name);
               object_name.printMovie();
          }
     }

     my_movies_list.printAllMovies();

     return 0;
}
