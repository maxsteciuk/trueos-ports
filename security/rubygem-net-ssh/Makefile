# Created by: Roderick van Domburg <r.s.a.vandomburg@student.utwente.nl>
# $FreeBSD$

PORTNAME=	net-ssh
PORTVERSION=	5.1.0
PORTEPOCH=	2
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Non-interactive SSH processing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

OPTIONS_DEFINE=	PROMPT_PASSPHRASES
OPTIONS_DEFAULT=PROMPT_PASSPHRASES
PROMPT_PASSPHRASES_DESC=	Prompt for passphrases on keys

USES=		gem shebangfix
USE_RUBY=	yes
SHEBANG_FILES=	support/ssh_tunnel_bug.rb

NO_ARCH=	yes

PROMPT_PASSPHRASES_RUN_DEPENDS=	rubygem-ruby-termios>=0:comms/rubygem-ruby-termios

.include <bsd.port.mk>
