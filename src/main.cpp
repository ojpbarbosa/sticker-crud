#include <iostream>
#include <string>
#include <vector>
#include "stickers.h"
#include "sticker.h"

using namespace std;

int main()
{
  cout << R"(
┌─┐┌┬┐┬┌─┐┬┌─┌─┐┬─┐   ┌─┐┬─┐┬ ┬┌┬┐
└─┐ │ ││  ├┴┐├┤ ├┬┘───│  ├┬┘│ │ ││
└─┘ ┴ ┴└─┘┴ ┴└─┘┴└─   └─┘┴└─└─┘─┴┘
  )" << endl;

  string filename;
  cout << "Digite o nome do arquivo: (./data/stickers.dat) ";
  getline(cin, filename);
  cout << endl;

  if (filename == "\n" || filename == "" || filename == " ")
  {
    filename = "./data/stickers.dat";
  }

  Stickers *stickers = new Stickers(filename);

  cout
      << stickers->count() << " figurinha(s) encontrada(s)!" << endl
      << endl;

  bool running = true;
  while (running)
  {
    cout << "0 - Sair" << endl;
    cout << "1 - Criar uma figurinha" << endl;
    cout << "2 - Atualizar uma figurinha" << endl;
    cout << "3 - Buscar uma figurinha" << endl;
    cout << "4 - Buscar todas as figurinhas" << endl;
    cout << "5 - Excluir uma figurinha" << endl;

    string option;
    cout << endl
         << "Digite a opção desejada: ";
    getline(cin, option);
    cout << endl;

    switch (option[0])
    {
    case '0':
      running = false;
      break;

    case '1':
    {
      Sticker *sticker = new Sticker();

      sticker->set_id(stickers->get_next_id());

      bool is_foil_valid = false;
      while (!is_foil_valid)
      {
        string foil;
        cout << "A figurinha é dourada (s/n): (s) ";
        getline(cin, foil);

        try
        {
          sticker->set_foil((foil[0] == 's' || foil[0] == 'S' || foil == "") ? true : false);
          is_foil_valid = true;
        }
        catch (invalid_argument &exception)
        {
          cout << endl
               << exception.what() << endl
               << endl;
        }
      }

      bool is_player_name_valid = false;
      while (!is_player_name_valid)
      {
        string player_name;
        cout << "Digite o nome do jogador: ";
        getline(cin, player_name);

        try
        {
          sticker->set_player_name(player_name);

          if (stickers->is_registered(sticker))
          {
            throw invalid_argument("Já existe uma figurinha com esse jogador!");
          }

          is_player_name_valid = true;
        }
        catch (invalid_argument &exception)
        {
          cout << endl
               << exception.what() << endl
               << endl;
        }
      }

      bool is_player_birth_date_valid = false;
      while (!is_player_birth_date_valid)
      {
        string player_birth_date;
        cout << "Digite a data de nascimento do jogador (dd-mm-aaaa): ";
        getline(cin, player_birth_date);

        try
        {
          sticker->set_player_birth_date(player_birth_date);
          is_player_birth_date_valid = true;
        }
        catch (invalid_argument &exception)
        {
          cout << endl
               << exception.what() << endl
               << endl;
        }
      }

      bool is_player_national_team_valid = false;
      while (!is_player_national_team_valid)
      {
        string player_national_team;
        cout << "Digite a seleção do jogador: ";
        getline(cin, player_national_team);

        try
        {
          sticker->set_player_national_team(player_national_team);
          is_player_national_team_valid = true;
        }
        catch (invalid_argument &exception)
        {
          cout << endl
               << exception.what() << endl
               << endl;
        }
      }

      bool is_player_joined_year_valid = false;
      while (!is_player_joined_year_valid)
      {
        int player_joined_year;
        cout << "Digite o ano de ingresso do jogador: ";
        cin >> player_joined_year;

        try
        {
          sticker->set_player_joined_year(player_joined_year);
          is_player_joined_year_valid = true;
        }
        catch (invalid_argument &exception)
        {
          cout << endl
               << exception.what() << endl
               << endl;
        }
      }

      bool is_player_weight_valid = false;
      while (!is_player_weight_valid)
      {
        float player_weight;
        cout << "Digite o peso do jogador: ";
        cin >> player_weight;

        try
        {
          sticker->set_player_weight(player_weight);
          is_player_weight_valid = true;
        }
        catch (invalid_argument &exception)
        {
          cout << endl
               << exception.what() << endl
               << endl;
        }
      }

      bool is_player_height_valid = false;
      while (!is_player_height_valid)
      {
        float player_height;
        cout << "Digite a altura do jogador: ";
        cin >> player_height;

        try
        {
          sticker->set_player_height(player_height);
          is_player_height_valid = true;
        }
        catch (invalid_argument &exception)
        {
          cout << endl
               << exception.what() << endl
               << endl;
        }
      }

      cin.ignore();
      cin.clear();
      fflush(stdin);

      cout << endl
           << *sticker << endl;

      bool is_create_sticker_valid = false;
      while (!is_create_sticker_valid)
      {
        string save;
        cout << "Salvar figurinha: (S/n) ";
        getline(cin, save);

        try
        {
          if (save[0] == 's' || save[0] == 'S' || save == "")
          {
            stickers->create(sticker);
            cout << endl
                 << "Figurinha salva com sucesso!" << endl
                 << endl;
            is_create_sticker_valid = true;
          }
          else if (save[0] == 'n' || save[0] == 'N')
          {
            cout << endl
                 << "Criação de figurinha abortada!" << endl
                 << endl;
            delete sticker;
          }
          else
          {
            throw invalid_argument("Opção inválida!");
          }
        }
        catch (invalid_argument &exception)
        {
          cout << endl
               << exception.what() << endl
               << endl;
        }
      }

      cin.clear();
      fflush(stdin);
    }
    break;

    case '2':
    {
      int id;
      cout
          << "Digite o ID da figurinha: ";
      cin >> id;

      cin.ignore(1, '\n');
      cin.clear();
      fflush(stdin);

      Sticker *sticker = stickers->find_by_id(id);

      if (sticker == nullptr)
      {
        cout << endl
             << "Não há figurinha com esse ID!" << endl
             << endl;
        break;
      }
      else
      {
        cout << endl
             << *sticker << endl;

        bool is_foil_valid = false;
        while (!is_foil_valid)
        {
          string foil;
          cout << "A figurinha é dourada (s/n)? ";
          getline(cin, foil);

          try
          {
            if (foil == "\n" || foil == "")
            {
              sticker->set_foil(sticker->get_foil());
            }
            else
            {
              sticker->set_foil((foil[0] == 's' || foil[0] == 'S') ? true : false);
            }

            is_foil_valid = true;
          }
          catch (invalid_argument &exception)
          {
            cout << endl
                 << exception.what() << endl
                 << endl;
          }
        }

        bool is_player_name_valid = false;
        while (!is_player_name_valid)
        {
          string player_name;
          cout << "Digite o nome do jogador: ";
          getline(cin, player_name);

          try
          {
            if (player_name == "\n" || player_name == "")
            {
              sticker->set_player_name(sticker->get_player_name());
            }
            else
            {
              sticker->set_player_name(player_name);
            }

            is_player_name_valid = true;
          }
          catch (invalid_argument &exception)
          {
            cout << endl
                 << exception.what() << endl
                 << endl;
          }
        }

        bool is_player_birth_date_valid = false;
        while (!is_player_birth_date_valid)
        {
          string player_birth_date;
          cout << "Digite a data de nascimento do jogador (dd-mm-aaaa): ";
          getline(cin, player_birth_date);

          try
          {
            if (player_birth_date == "\n" || player_birth_date == "")
            {
              sticker->set_player_birth_date(sticker->get_player_birth_date());
            }
            else
            {
              sticker->set_player_birth_date(player_birth_date);
            }

            is_player_birth_date_valid = true;
          }
          catch (invalid_argument &exception)
          {
            cout << endl
                 << exception.what() << endl
                 << endl;
          }
        }

        bool is_player_national_team_valid = false;
        while (!is_player_national_team_valid)
        {
          string player_national_team;
          cout << "Digite a seleção do jogador: ";
          getline(cin, player_national_team);

          try
          {
            if (player_national_team == "\n" || player_national_team == "")
            {
              sticker->set_player_national_team(sticker->get_player_national_team());
            }
            else
            {
              sticker->set_player_national_team(player_national_team);
            }

            is_player_national_team_valid = true;
          }
          catch (invalid_argument &exception)
          {
            cout << endl
                 << exception.what() << endl
                 << endl;
          }
        }

        bool is_player_joined_year_valid = false;
        while (!is_player_joined_year_valid)
        {
          string player_joined_year;
          cout << "Digite o ano de ingresso do jogador: ";
          getline(cin, player_joined_year);

          try
          {
            if (player_joined_year == "\n" || player_joined_year == "")
            {
              sticker->set_player_joined_year(sticker->get_player_joined_year());
            }
            else
            {
              sticker->set_player_joined_year(atoi(player_joined_year.c_str()));
            }

            is_player_joined_year_valid = true;
          }
          catch (invalid_argument &exception)
          {
            cout << endl
                 << exception.what() << endl
                 << endl;
          }
        }

        bool is_player_weight_valid = false;
        while (!is_player_weight_valid)
        {
          string player_weight;
          cout << "Digite o peso do jogador: ";
          getline(cin, player_weight);

          try
          {
            if (player_weight == "\n" || player_weight == "")
            {
              sticker->set_player_weight(sticker->get_player_weight());
            }
            else
            {
              sticker->set_player_weight(atof(player_weight.c_str()));
            }

            is_player_weight_valid = true;
          }
          catch (invalid_argument &exception)
          {
            cout << endl
                 << exception.what() << endl
                 << endl;
          }
        }

        bool is_player_height_valid = false;
        while (!is_player_height_valid)
        {
          string player_height;
          cout << "Digite a altura do jogador: ";
          getline(cin, player_height);

          try
          {
            if (player_height == "\n" || player_height == "")
            {
              sticker->set_player_height(sticker->get_player_height());
            }
            else
            {
              sticker->set_player_height(atof(player_height.c_str()));
            }

            is_player_height_valid = true;
          }
          catch (invalid_argument &exception)
          {
            cout << endl
                 << exception.what() << endl
                 << endl;
          }
        }

        cin.clear();
        fflush(stdin);

        cout << endl
             << *sticker << endl;

        bool is_update_sticker_valid = false;
        while (!is_update_sticker_valid)
        {
          string save;
          cout << "Atualizar figurinha: (S/n) ";
          getline(cin, save);

          try
          {
            if (save[0] == 's' || save[0] == 'S' || save == "")
            {
              stickers->update(sticker);
              cout << endl
                   << "Figurinha atualizada com sucesso!" << endl
                   << endl;
              is_update_sticker_valid = true;
            }
            else if (save[0] == 'n' || save[0] == 'N')
            {
              cout << endl
                   << "Atualização de figurinha abortada!" << endl
                   << endl;
              delete sticker;
            }
            else
            {
              throw invalid_argument("Opção inválida!");
            }
          }
          catch (invalid_argument &exception)
          {
            cout << endl
                 << exception.what() << endl
                 << endl;
          }
        }
      }

      cin.clear();
      fflush(stdin);
    }
    break;

    case '3':
    {
      cout << "Criérios da busca: " << endl
           << endl;
      cout << "1 - ID da figurinha" << endl;
      cout << "2 - Nome do jogador" << endl;

      cout << endl
           << "Critério: ";
      char criteria;
      cin >> criteria;

      cin.ignore();
      cin.clear();
      fflush(stdin);

      switch (criteria)
      {
      case '1':
      {
        int id;
        cout << endl
             << "Digite o ID da figurinha: ";
        cin >> id;

        cin.ignore();
        cin.clear();
        fflush(stdin);

        Sticker *sticker = stickers->find_by_id(id);

        if (sticker == nullptr)
        {
          cout << endl
               << "Não há figurinha com esse ID!" << endl
               << endl;
          break;
        }

        cout << *sticker << endl;
      }
      break;
      case '2':
      {
        string name;
        cout << endl
             << "Digite o nome do jogador: ";
        getline(cin, name);

        cin.ignore();
        cin.clear();
        fflush(stdin);

        Sticker *sticker = stickers->find_by_player_name(name);

        if (sticker == nullptr)
        {
          cout << endl
               << "Não há jogador com esse nome!" << endl
               << endl;
          break;
        }

        cout << *sticker << endl;
      }
      break;
      default:
        cout << "Opção inválida!" << endl
             << endl;
        break;
      }

      cin.clear();
      fflush(stdin);
    }
    break;

    case '4':
    {
      vector<Sticker *> all_stickers = stickers->find_all();

      if (all_stickers.size() == 0)
      {
        cout
            << "Não há figurinhas cadastradas!" << endl
            << endl;
        break;
      }

      for (Sticker *sticker : all_stickers)
      {
        cout << *sticker << endl;
      }
    }
    break;

    case '5':
    {
      int id;
      cout
          << "Digite o ID da figurinha: ";
      cin >> id;

      cin.ignore();
      cin.clear();
      fflush(stdin);

      Sticker *sticker = stickers->find_by_id(id);

      if (sticker == nullptr)
      {
        cout << endl
             << "Não há figurinha com esse ID!" << endl
             << endl;
        break;
      }

      cout << endl
           << *sticker << endl;

      bool is_delete_sticker_valid = false;
      while (!is_delete_sticker_valid)
      {
        string delete_sticker;
        cout << "Deseja deletar essa figurinha? (S/n) ";
        getline(cin, delete_sticker);

        try
        {
          if (delete_sticker[0] == 's' || delete_sticker[0] == 'S' || delete_sticker == "")
          {
            stickers->exclude(sticker);
            cout << endl
                 << "Figurinha deletada com sucesso!" << endl
                 << endl;
            is_delete_sticker_valid = true;
          }
          else if (delete_sticker[0] == 'n' || delete_sticker[0] == 'N')
          {
            cout << endl
                 << "Exclusão de figurinha abortada!" << endl
                 << endl;
            is_delete_sticker_valid = true;
          }
          else
          {
            throw invalid_argument("Opção inválida!");
          }
        }
        catch (invalid_argument &exception)
        {
          cout << endl
               << exception.what() << endl
               << endl;
        }
      }

      cin.clear();
      fflush(stdin);
    }
    break;

    default:
      cout << "Opção inválida!" << endl
           << endl;
      break;
    }
  }

  return 0;
}
