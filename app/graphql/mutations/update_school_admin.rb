module Mutations
  class UpdateSchoolAdmin < GraphQL::Schema::Mutation
    argument :id, ID, required: true
    argument :name, String, required: true
    argument :email, String, required: true

    description "Create a new school admin"

    field :success, Boolean, null: false

    def resolve(params)
      mutator = UpdateSchoolAdminMutator.new(params, context)

      if mutator.valid?
        { success: mutator.save }
      else
        mutator.notify_errors
        { success: false }
      end
    end
  end
end
