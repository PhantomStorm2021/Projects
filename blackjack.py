global str
import random 
dealer_cards = []
player_cards = []

while len(dealer_cards) != 2:
    dealer_cards.append(random.randint(1,11))
    if len(dealer_cards) == 2:
        print("Dealer Has X & ", dealer_cards[1])

while len(player_cards) != 2:
    player_cards.append(random.randint(1,11))
    if len(player_cards) == 2:
        print("You Have", player_cards)

if sum(dealer_cards) == 21:
    print("Dealer Has 21 & Wins")
elif sum(dealer_cards) > 21:
    print("Dealer Has Busted")

while sum(player_cards) < 21:
    input = str(input("Do You Want To Hit Or Stay: "))
    if input == "Hit":
        player_cards.append(random.randint(1,11))
        print("You Currently Have A Total Off " + str(sum(player_cards)) + "From These Cards", player_cards)
    else:
        print("The Dealer Has A Total Off " + str(sum(dealer_cards)) + "Including", dealer_cards)
        print("You Have A Total Off " + str(sum(player_cards)) + "Including", player_cards)
        if sum(dealer_cards) > sum(player_cards):
            print("Dealer Wins")
        else:
            print("You Win The Game!")
            break

if sum(player_cards) > 21:
    print("You Have Gone Bust, Dealer Wins")
elif sum(player_cards) == 21:
    print("You Have BLACKJACK, You Win")