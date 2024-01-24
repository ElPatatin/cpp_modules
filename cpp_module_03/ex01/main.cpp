/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpeset-c <cpeset-c@student.42barce.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:15:35 by cpeset-c          #+#    #+#             */
/*   Updated: 2024/01/24 16:16:54 by cpeset-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iomanip>

#define FILL 60

void	attacking( ClapTrap& clap1, ClapTrap& clap2 )
{
	bool	canAttack;

	canAttack = clap1.getEnergyPoints() < 1 ? false : true;
	clap1.attack( clap2.getName() );
	if ( canAttack == true )
		clap2.takeDamage( clap1.getAttackDamage() );
}

void	war( ClapTrap& one, ClapTrap& two, int times )
{
	for ( int i = 0; i < times; i++ )
	{
		attacking( one, two );
		attacking( two, one );
	}
}

void	test( ClapTrap& one, ClapTrap& two, bool change_dmg )
{
	war( one, two, 1 );
	if ( change_dmg == true )
		one.setAttackDamage( 1 );
	attacking( one, two );
	if ( change_dmg == true )
		two.setAttackDamage( 1 );
	attacking( two, one );
	if ( change_dmg == true )
		one.setAttackDamage( 8 );
	attacking( one, two );
	if ( change_dmg == true )
		two.setAttackDamage( 6 );
	std::cout << std::endl;
	one.beRepaired( one.getAttackDamage() * 10 );
	two.beRepaired( one.getAttackDamage() * 10 );
	std::cout << std::endl;
	attacking( two, one );
	war( one, two, 1 );
	if ( change_dmg == true )
	{
		one.setAttackDamage( 1 );
		two.setAttackDamage( 1 );
	}
	war( one, two, 6 );
	std::cout << "\none -> Name: " << one.getName() << " | HP: " << one.getHitPoints() << " | EP: " << one.getEnergyPoints() << " | AD: " << one.getAttackDamage() << std::endl;
    std::cout << "two -> Name: " << two.getName() << " | HP: " << two.getHitPoints() << " | EP: " << two.getEnergyPoints() << " | AD: " << two.getAttackDamage() << std::endl;
}

void	print_next_test( std::string msg )
{
	int	fill;
	int	odd;

	fill = ( FILL - msg.length() ) / 2;
	odd = msg.length() % 2;
	std::cout << "\n " << std::setfill('_') << std::setw(FILL - 1) << "" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw( fill + odd ) << "" << msg << std::setw( fill ) << "|" << std::endl;
	std::cout << "|" << std::setfill(' ') << std::setw(FILL) << "|" << std::endl;
	std::cout << "|" << std::setfill('_') << std::setw(FILL + 1) << "|\n" << std::endl;
}

void	test_clap( void )
{
	ClapTrap	clap1( "clap1" );
	ClapTrap	clap2( clap1 );

	clap2.setName( "clap2" );
	std::cout << "\nclap1 -> Name: " << clap1.getName() << " | HP: " << clap1.getHitPoints() << " | EP: " << clap1.getEnergyPoints() << " | AD: " << clap1.getAttackDamage() << std::endl;
    std::cout << "clap2 -> Name: " << clap2.getName() << " | HP: " << clap2.getHitPoints() << " | EP: " << clap2.getEnergyPoints() << " | AD: " << clap2.getAttackDamage() << std::endl;
	test( clap1, clap2, true );
	std::cout << std::endl;
}

void	test_scav( void )
{
	ScavTrap	scav1;
	ScavTrap	scav2( "scav2" );

	scav1 = scav2;
	scav1.setName( "scav1" );
	std::cout << "\nscav1 -> Name: " << scav1.getName() << " | HP: " << scav1.getHitPoints() << " | EP: " << scav1.getEnergyPoints() << " | AD: " << scav1.getAttackDamage() << std::endl;
    std::cout << "scav2 -> Name: " << scav2.getName() << " | HP: " << scav2.getHitPoints() << " | EP: " << scav2.getEnergyPoints() << " | AD: " << scav2.getAttackDamage() << std::endl;
	test( scav1, scav2, false );
	std::cout << std::endl;
	scav1.guardGate();
	scav2.guardGate();
	std::cout << std::endl;
}

int	main( void )
{
	print_next_test( "ClapTrap test" );
	test_clap();

	print_next_test( "ScravTrap test" );
	test_scav();

	return ( 0 );
}