#!/bin/sh

SOURCEDIR=doc/source/contributor/api

if [ ! -d ${SOURCEDIR} ] ; then
    mkdir -p ${SOURCEDIR}
fi

for x in `./doc/find_autodoc_modules.sh`;
do
  echo "Generating ${SOURCEDIR}/${x}.rst"
  echo "${SOURCEDIR}/${x}.rst" >> .autogenerated 
  heading="The :mod:\`${x}\` Module"
  # Figure out how long the heading is
  # and make sure to emit that many '=' under
  # it to avoid heading format errors
  # in Sphinx.
  heading_len=$(echo "$heading" | wc -c)
  underline=$(head -c $heading_len < /dev/zero | tr '\0' '=')
  ( cat <<EOF
${heading}
${underline}

.. automodule:: ${x}
  :members:
  :undoc-members:
  :show-inheritance:
EOF
) > ${SOURCEDIR}/${x}.rst

done

if [ ! -f ${SOURCEDIR}/autoindex.rst ] ; then

    cat > ${SOURCEDIR}/autoindex.rst <<EOF 
.. toctree::
   :maxdepth: 1

EOF
    for f in `cat .autogenerated | sort` ; do
        relative=`echo ${f} | sed -e 's$^'${SOURCEDIR}'/$$'`
        echo "   ${relative}" >> ${SOURCEDIR}/autoindex.rst
    done

    echo ${SOURCEDIR}/autoindex.rst >> .autogenerated
fi