import os
import time
import random


class Villain:
    
    def __init__(self, shield = 1):
        
        
        self.health = 100
        self.energy = 500
        self.shield = shield
        
        
        
    def attack(self, Villain , weapon):
              
        self.energy -= weapon.energy        
        Villain.health -= weapon.damage * Villain.shield
        
        if weapon.resources != 'inf':
            weapon.resources -= 1
                
        
        
    def defend(self, sheild):
        
            self.energy -= sheild.energy        
            self.shield = sheild.save

            if sheild.resources != 'inf':
                sheild.resources -= 1
                

            
    
    
    def reset_sheild(self):
        
        self.sheild = 1
        
        
    def is_enough_energy(self, item):
        if self.energy >= item.energy:
            return True
        else:
            return False
    
        
    
    
    
class Weapon:
    
    def __init__(self, energy,damage, resources):
        
        self.energy = energy
        self.damage = damage
        self.resources = resources
        
    def canUse(self):
        if self.resources == 'inf' or self.resources > 0 :
            return True
        else:
            return False
        
        
        
        
class Sheild:
    
    def __init__(self, energy, save, resources):
        
        self.energy = energy
        self.save = save
        self.resources = resources
        
    def canUse(self):
        if self.resources == 'inf' or self.resources > 0 :
            return True
        else:
            return False

    



#the villains
Gru = Villain()
Vector = Villain()
    

#Gru's weapons    
FreezGun = Weapon(50, 11, 'inf')
ElectricProd = Weapon(88, 18, 5)
MegaMagnet = Weapon(92, 10, 3)
KalmanMissiles = Weapon(120, 20, 1)

#Gru's sheilds
BarrierGun = Sheild(20, 0.4, 'inf')
SelectivePermeability = Sheild(50, 0.9, 2)


#Vector's weapons
laser_blasters = Weapon(40, 8, 'inf')#1
plasma_grenades = Weapon(56, 13, 8)#2
sonic_canon = Weapon(100, 22, 3)#3

#Vector's sheilds
energyNet = Sheild(15, 0.32, 'inf')#4
deflector = Sheild(40, 0.8, 3)#5



##GUI  function
def update_screen():
    
    print("  Gru \t\t\t Vector")
 ##################Health Bar#######################   
    for i in range(int(Gru.health//10)):
        print('=', end="")
    for i in range(int(10 - Gru.health//10)):
        print("-", end="")
        
    print('   Health   ', end="")
        
        
    for i in range(int(10 - Vector.health//10)):
        print("-", end="")
    for i in range(int(Vector.health//10)):
        print('=', end="")
        
    print("")
#####################Energy Bar##############    
    for i in range(int(Gru.energy//50)):
        print('=', end="")
    for i in range(int(10 - Gru.energy//50)):
        print("-", end="")
        
    print('   Energy   ', end="")
        
        
    for i in range(int(10 - Vector.energy//50)):
        print("-", end="")
    for i in range(int(Vector.energy//50)):
        print('=', end="")
        
    print("\n")




############################# main loop #################################
print("Gru starts")
while True:
    
    ####Gru's turn
    
    update_screen()
    
    if Vector.health <=0 or Gru.health <=0:
        break
    
    if Vector.energy <=0 or Gru.energy <=0:
        break
    
    #variable to store the choice
    answer = '0'
    
    while answer != '1' and answer != '2':
        print("What do you want to do?")
        print("1. attack")
        print("2. Defend")
        
        answer = input()
        
        if answer != '1' and answer != '2':
            
            print("\n\nInvalid Answer!")
            time.sleep(1)
            os.system('cls')
            update_screen()
            
    #User chose violence
    if answer == '1':     
        while answer not in range(1,5):
            
        
            
            print("You chose violence!")            
            print("Choose your weapon:")
            print("1. Freez Gun \n2. ElectricProd \n3. MegaMagnet \n4. KalmanMissiles")
            
            answer = int(input())
            
                
            if answer == 1:
                weapon = FreezGun
            elif answer == 2:
                weapon = ElectricProd
            elif answer == 3:
                weapon = MegaMagnet
            elif answer == 4:
                weapon = KalmanMissiles
            else:
                print("\n\nInvalid Answer!")
                time.sleep(1)
                os.system('cls')            
                continue
                
            if not Gru.is_enough_energy(weapon):
                print("\n\nNo enough energy to use item")
                time.sleep(1)
                os.system('cls')
                answer = 0
                continue
                
            if not weapon.canUse():
                print("\n\nYou can't use this weapon any more!")
                time.sleep(1)
                os.system('cls')
                answer = 0
                continue
            
            Gru.attack(Vector, weapon)
            
            
            
    ####if user chose peace
    if answer == '2': 
        while answer not in range(1,3):
            

            print("Defend")            
            print("Choose your Sheild:")
            print("1. BarrierGun \n2. SelectivePermeability ")
            
            answer = int(input())
            
                
            if answer == 1:
                sheild = BarrierGun
            elif answer == 2:
                sheild = SelectivePermeability
            else:
                print("\n\nInvalid Answer!")
                time.sleep(1)
                os.system('cls')            
                continue
                
                
            if not Gru.is_enough_energy(sheild):
                print("\n\nNo enough energy to use item")
                time.sleep(1)
                os.system('cls')
                answer = 0
                continue
                
            if not sheild.canUse():
                print("\n\nYou can't use this weapon any more!")
                time.sleep(1)
                os.system('cls')
                answer = 0
                continue
            
            Gru.defend(sheild)
            
    #sheilds expire after one round
    Vector.reset_sheild()
        
    
    #vector's turn
    while True:
        play = random.randint(1, 5)
        gadget_name = ""
        
        if play == 1:
            gadget = laser_blasters
            gadget_name = "Laser Blasters"
        elif play == 2:
            gadget = plasma_grenades
            gadget_name = "Plasma Grenades"
        elif play == 3:
            gadget = sonic_canon
            gadget_name = "Sonic canon"
        elif play == 4:
            gadget = energyNet
            gadget_name = "Energy Net"
        elif play == 5:
            gadget = deflector
            gadget_name = "Deflector"
        
        
        if not Vector.is_enough_energy(gadget):
            continue
            
        if not gadget.canUse():
            continue
        
        if play < 4:
            Vector.attack(Gru, gadget)
            print(f"Vector chose to attack you using {gadget_name}")
        else:
            print(f"Vector chose to deffend you using his {gadget_name}")
            Vector.defend(gadget)
            
        time.sleep(1.5)
        os.system('cls')
        #sheilds expire after one round
        Gru.reset_sheild()
        break
            
            
       
                
        
        
            
        
        
    
